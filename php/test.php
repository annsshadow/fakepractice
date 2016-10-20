<?php
/*
$origin_url = 'http://test-1000000001.test.mytest.com/test.apk';
echo 'origin_url:', $origin_url, '<br />';

//get id
$appid_pattern = "/-[0-9]\d";
preg_match($appid_pattern, $origin_url, $appid_before);
echo 'id_before:', $appid_before[0], '<br />';
$appid_after = str_replace("-", "/", $appid_before[0]);
echo 'id_after:', $appid_after, '<br />';
$appid = str_replace("/", "", $appid_after);
echo 'pid:', $appid, '<br />';

//get bucket
$bucket_pattern = "/\/\w+/";
preg_match($bucket_pattern, $origin_url, $bucket_after);
echo 'bucket_after:', $bucket_after[0], '<br />';
$bucket = str_replace("/", "", $bucket_after[0]);
echo 'bucket:', $bucket, '<br />';

//get file
$file_pattern = "/com\/.*$/";
preg_match($file_pattern, $origin_url, $file_before);
echo 'file_before:', $file_before[0], '<br />';
$file_after = str_replace("com", "", $file_before[0]);
echo 'file_after:', $file_after, '<br />';
$file_urldecode = urldecode($file_after);
echo 'file_urldecode:', $file_urldecode, '<br />';
$file = str_replace("/", "", $file_urldecode);
echo 'file:', $file, '<br />';

//connect all params
$query = $appid_after . $bucket_after[0] . $file_urldecode;
echo 'query:', $query, '<br />';

//timezone set
date_default_timezone_set('Asia/Shanghai');
$optime = date("Y-m-d H:i:s", time());
echo 'optime:', $optime, '<br /><br />';

//test multi array
$multiarr = array();
$multiarr[0][] = 'test00';
$multiarr[0][] = 'test01';
$multiarr[1][] = 'test10';
$multiarr[1][] = 'test11';

print_r($multiarr);
echo '<br />';
var_dump($multiarr);
echo '<br /><br />';

//test arsort
$nums = array("d" => 0.004, "a" => 0.003, "b" => 0.005, "c" => 0.002);
arsort($nums);
foreach ($nums as $key => $val) {
    echo "$key = $val\n";
}
echo '<br /><br />';

//sort array by another array
$customer['address'] = '123 fake st';
$customer['name'] = 'Tim';
$customer['dob'] = '12/08/1986';
var_dump($customer);
echo '<br />';

$properOrderedArray = array_merge(array_flip(array('name', 'dob', 'address')), $customer);
var_dump($properOrderedArray);
echo '<br />';

$properOrderedArray = array_replace(array_flip(array('name', 'dob', 'address')), $customer);
var_dump($properOrderedArray);
echo '<br />';

$customer2['address-1000'][] = '123';
$customer2['address-1000'][] = '0.123';
$customer2['address-1000'][] = '1.2';
$customer2['name-1222'][] = '234';
$customer2['name-1222'][] = '23.4';
$customer2['name-1222'][] = '0.4';
$customer2['dob-2333'][] = '0.6';
$customer2['dob-2333'][] = '0.7';
$customer2['dob-2333'][] = '1.8';
print_r($customer2);
echo '<br />';

$properOrderedArray = array_merge(array_flip(array('name-1222', 'dob-2333', 'address-1000')), $customer2);
print_r($properOrderedArray);
echo '<br />';

$properOrderedArray2 = array_replace(array_flip(array('name-1222', 'dob-2333', 'address-1000')), $customer2);
print_r($properOrderedArray2);
echo '<br /><br />';

//test array_slice
$a = array("a" => "red", "b" => "green", "c" => "blue", "d" => "yellow", "e" => "brown");
print_r($a);
echo '<br />';
print_r(array_slice($properOrderedArray, 0, 2));
echo '<br />';

$a = array("0" => "red", "1" => "green", "2" => "blue", "3" => "yellow", "4" => "brown");
print_r($a);
echo '<br />';
print_r(array_slice($properOrderedArray2, 1, 2, true));
echo '<br /><br />';
*/

//设置时区，判断是否是当天第一次拉取
date_default_timezone_set("Asia/Shanghai");
$curHi = date("H:i");
$cur_time = strtotime($curHi);
$min_time = strtotime('00:00');
//edg_time是用来在后续插入数据前判断是属于昨天的还是今天的
$edg_time = $min_time - 120;
$max_time = strtotime('00:18');
//如果是第一次拉取，将开始日期设置为昨天，为了能拉到昨天最后一个值，否则设置为今天
if ($cur_time > $min_time && $cur_time < $max_time) {
    $yesterday = date("Y-m-d", strtotime("-1 day"));
    $beg_date = $yesterday;
    $today = date("Y-m-d", time());
} else {
    $today = date("Y-m-d", time());
    $beg_date = $today;
}
//打印变量信息
echo 'curHi:', $curHi, '<br />';
echo 'cur_time:', $cur_time, '<br />';
echo 'min_time', $min_time, '<br />';
echo 'edg_time:', $edg_time, '<br />';
echo 'max_time:', $max_time, '<br />';
echo 'yesterday:', $beg_date, '--->today:', $today, '<br />';

$second = 1476721500;

if($second < $edg_time){
    echo $second,' < ',$edg_time;
}
else{
    echo $second,' > ',$edg_time;
}