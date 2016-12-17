//
// Created by Administrator on 2016/11/10.
//

#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 100000;
struct bign
{
	int len, s[maxn];
	bign()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}
	bign operator = (const char* num)
	{
		len = strlen(num);
		for(int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
		return *this;
	}
	bign operator = (int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	bign(const char* num)
	{
		*this = num;   //applicable to initialization
	}
	bign(int num)
	{
		*this = num;
	}
	string str() const
	{
		string res = "";
		for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if(res == "") res = "0";
		return res;
	}
	bign operator + (const bign& b) const
	{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; g || i < max(len, b.len); i++)
		{
			int x = g;
			if(i < len) x += s[i];
			if(i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}
	bign operator += (const bign& b)
	{
		*this = *this + b;
		return *this;
	}
	void clean()
	{
		while(len > 1 && !s[len - 1]) len--;
	}
	bign operator * (const bign &b)
	{
		bign c;
		c.len = len + b.len;
		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < b.len; j++)
			{
				c.s[i + j] += s[i] * b.s[j];
			}
		}
		for(int i = 0; i < c.len; i++)
		{
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}
	bign operator *= (const bign &b)
	{
		*this = *this * b;
		return *this;
	}
	bign operator - (const bign &b)
	{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; i < len; i++)
		{
			int x = s[i] - g;
			if(i < b.len) x -= b.s[i];
			if(x >= 0) g = 0;
			else
			{
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	bign operator -= (const bign &b)
	{
		*this = *this - b;
		return *this;
	}
	bign operator / (const bign &b)
	{
		bign c, f = 0;
		for(int i = len - 1; i >= 0; i--)
		{
			f = f * 10;
			f.s[0] = s[i];
			while(f >= b)
			{
				f -= b;
				c.s[i]++;
			}
		}
		c.len = len;
		c.clean();
		return c;
	}
	bign operator /= (const bign &b)
	{
		*this  = *this / b;
		return *this;
	}
	bign operator % (const bign &b)
	{
		bign r = *this / b;
		r = *this - r * b;
		return r;
	}
	bign operator %= (const bign &b)
	{
		*this = *this % b;
		return *this;
	}
	bool operator <(const bign& b) const
	{
		if(len != b.len) return len < b.len;
		for(int i = len - 1; i >= 0; i--)
			if(s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
	bool operator >(const bign& b) const
	{
		return b < *this;
	}
	bool operator <=(const bign& b) const
	{
		return !(b < *this);
	}
	bool operator >=(const bign& b) const
	{
		return !(*this < b);
	}
	bool operator !=(const bign& b) const
	{
		return b < *this || *this < b;
	}
	bool operator ==(const bign& b) const
	{
		return !(b < *this) && !(*this < b);
	}



};
istream& operator >> (istream &in, bign& x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const bign& x)
{
	out << x.str();
	return out;
}

int main()
{
	bign a, b;
	cin >> a >> b;
	cout << a*b << endl;

	return 0;
}
