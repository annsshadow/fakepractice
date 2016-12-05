#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sys/time.h>

#define CHAR_SIZE 8
#define TEST_TIMES 100000
#define EXPECT_FALSE_POSITIVE 0.0002
#define INIT_HASH_SEED 0xca7debf3
//设置的原因是让生成的数字都不属于已插入的元素数组的，所以插入元素个数不能大于这个值
#define MAX_BEGIN 100000000

using namespace std;

inline uint32_t cpy_decode(const char* origin)
{
    //直接载入
    uint32_t result;
    memcpy(&result, origin, sizeof(result));
    return result;
}

//模拟murmurhash3的实现
uint32_t fake_hash(const char* data, size_t len, uint32_t fake_seed)
{
    //随机设置m和r
    const uint32_t m = INIT_HASH_SEED;
    const uint32_t r = 24;
    const char* data_end = data + len;
    uint32_t h = fake_seed ^ (len * m);

    //每次处理4个字节
    while (data + 4 <= data_end)
    {
        uint32_t split = cpy_decode(data);
        data += 4;
        h += split;
        h *= m;
        h ^= (h >> 16);
    }

    //处理剩下的字节
    switch (data_end - data)
    {
    case 3:
        h += static_cast<unsigned char>(data[2]) << 16;
    case 2:
        h += static_cast<unsigned char>(data[1]) << 8;
    case 1:
        h += static_cast<unsigned char>(data[0]);
        h *= m;
        h ^= (h >> r);
        break;
    }

    return h;
}

//定义元素类
class Element
{
public:
    Element(const int32_t ele);
    uint32_t hash(uint32_t fake_seed) const;
private:
    int32_t _ele;
};
//构造赋值
Element::Element(const int32_t ele)
    : _ele(ele)
{
}

//元素hash函数wrapper
uint32_t Element::hash(uint32_t fake_seed) const
{
    return fake_hash(reinterpret_cast<const char *>(&_ele), sizeof(_ele), fake_seed);
}

//定义bloom filter类
template<typename T>
class fakeBloomFilter
{
public:
    fakeBloomFilter(const int32_t ele_num, const double false_positive);
    void insert(const T &ele);
    void insert2(const T &ele);
    bool check(const T &ele);
    bool check2(const T &ele);

private:
    std::vector<char> _bits;
    int32_t _k;
    int32_t _m;
    int32_t _n;
    double _p;
};

//构造赋值
template<typename T>
fakeBloomFilter<T>::fakeBloomFilter(const int32_t ele_num, const double false_positive)
    : _bits(), _k(0), _m(0), _n(ele_num), _p(false_positive)
{
    _m = static_cast<int32_t>(1.44 * _n * log(1 / _p) / log(2));
    //+1是为了向上取整hash函数次数
    _k = static_cast<int32_t>(log(2) * _m / _n + 1);
    cout << "位数组长度:" << _m
         << "\thash函数次数:" << _k;
    //+7是为了向上取整大小
    _bits.resize((_m + CHAR_SIZE - 1) / CHAR_SIZE, 0);
}

//耗时较长的插入函数
template<typename T>
void fakeBloomFilter<T>::insert(const T &ele)
{
    uint32_t hash_result = INIT_HASH_SEED;

    //经过多次hash，将对应位的值设置为1
    for (int i = 0; i < _k; ++i)
    {
        hash_result = ele.hash(hash_result);
        const uint32_t bit_pos = hash_result % _m;
        _bits[bit_pos / CHAR_SIZE] |= 1 << (bit_pos % CHAR_SIZE);
    }
}

//耗时较短的插入函数
template<typename T>
void fakeBloomFilter<T>::insert2(const T &ele)
{
    uint32_t hash_result = ele.hash(INIT_HASH_SEED);

    //经过多次hash，将对应位的值设置为1
    const uint32_t delta = (hash_result >> 17) | (hash_result << 15);
    for (int i = 0; i < _k; ++i)
    {
        const uint32_t bit_pos = hash_result % _m;
        _bits[bit_pos / CHAR_SIZE] |= 1 << (bit_pos % CHAR_SIZE);
        hash_result += delta;
    }
}

//对应耗时较长的检查函数
template<typename T>
bool fakeBloomFilter<T>::check(const T &ele)
{
    uint32_t hash_result = INIT_HASH_SEED;

    //经过多次hash，只要有某一位为0则判断为不存在
    for (int i = 0; i < _k; ++i)
    {
        hash_result = ele.hash(hash_result);
        const uint32_t bit_pos = hash_result % _m;
        if ((_bits[bit_pos / CHAR_SIZE] & (1 << (bit_pos % CHAR_SIZE))) == 0)
        {
            return false;
        }
    }
    return true;
}

//对应耗时较短的检查函数
template<typename T>
bool fakeBloomFilter<T>::check2(const T &ele)
{
    uint32_t hash_result = ele.hash(INIT_HASH_SEED);

    //经过多次hash，只要有某一位为0则判断为不存在
    const uint32_t delta = (hash_result >> 17) | (hash_result << 15);
    for (int i = 0; i < _k; ++i)
    {
        const uint32_t bit_pos = hash_result % _m;
        if ((_bits[bit_pos / CHAR_SIZE] & (1 << (bit_pos % CHAR_SIZE))) == 0)
        {
            return false;
        }
        hash_result += delta;
    }
    return true;
}

//定义测试类
class fakeTest
{
public:
    fakeTest(const int32_t ele_nums, const double expected_false_positive);
    void beg_all_test(bool use_less_time_hash);
private:
    void insert_eles_into_arr(bool use_less_time_hash);
    void get_false_positive_rates(bool use_less_time_hash, int test_times);
    int32_t _ele_num;
    double _expected_positive;
    fakeBloomFilter<Element> _bloom;
};

//构造赋值
fakeTest::fakeTest(const int32_t ele_nums, const double expected_false_positive)
    : _ele_num(ele_nums), _expected_positive(expected_false_positive), _bloom(ele_nums, _expected_positive)
{
}

//开始所有测试
void fakeTest::beg_all_test(bool use_less_time_hash)
{
    //用time-times个不属于位数组的元素去测试real_false_positive
    int test_times = TEST_TIMES;
    cout << "\t\t测试元素数量:" << test_times;
    insert_eles_into_arr(use_less_time_hash);
    get_false_positive_rates(use_less_time_hash, test_times);
}

//插入元素到位数组中,可选是否使用耗时较少的hash函数
void fakeTest::insert_eles_into_arr(bool use_less_time_hash)
{
    struct  timeval  start;
    struct  timeval  end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i = 1; i <= _ele_num; ++i)
    {
        const Element ele(i);
        if (use_less_time_hash)
        {
            _bloom.insert2(ele);
        }
        else
        {
            _bloom.insert(ele);
        }
    }
    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    cout << "\t插入耗时:" << timer << "us";
}

//测试函数，可选是否使用耗时较少的hash函数
void fakeTest::get_false_positive_rates(bool use_less_time_hash, int test_times)
{
    struct  timeval  start;
    struct  timeval  end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    int wrong_matches = 0;
    long max_beg = MAX_BEGIN;

    for (int i = 0; i < test_times; i++)
    {
        //生成去检验的ele，一旦匹配就证明是错误匹配
        const Element ele(i + max_beg);
        //判断是否存在并记录
        if (use_less_time_hash)
        {
            if (_bloom.check2(ele))
            {
                wrong_matches++;
            }
        }
        else
        {
            if (_bloom.check(ele))
            {
                wrong_matches++;
            }
        }
    }
    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    cout << "\t\t检查耗时:" << timer << "us"
         << endl;
    cout << "元素数量:" << _ele_num
         << "\t\t期望错误率:" << _expected_positive
         << "\t错误命中个数: " << wrong_matches
         << "\t实际错误率:" << static_cast<float>(wrong_matches * 1.0 / test_times)
         << endl;
}

//测试函数wrapper-分别测试元素数量从1w到10w
void get_false_positive_rates(void)
{
    cout << "第一轮：使用耗时较多的hash函数" << endl;
    for (int i = 0; i < 10; ++i)
    {
        fakeTest test(10000 + i * 10000, EXPECT_FALSE_POSITIVE);
        test.beg_all_test(false);
    }

    cout << endl << "第二轮：使用耗时较少的hash函数" << endl;
    for (int i = 0; i < 10; ++i)
    {
        fakeTest test(10000 + i * 10000, EXPECT_FALSE_POSITIVE);
        test.beg_all_test(true);
    }
}

//主函数
int main(int argc, char* argv[])
{
    struct  timeval  start;
    struct  timeval  end;
    unsigned long timer;
    gettimeofday(&start, NULL);

    //调用测试函数
    get_false_positive_rates();

    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    cout << endl << "程序整体耗时:" << timer << "us" << endl;

    return 0;
}
