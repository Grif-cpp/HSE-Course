#include <iostream>
#include <vector>
#include <string>

bool operator ==(bigint& a, bigint& b)
{
	int a1 = a.arr.size(), b1 = b.arr.size();
	if (a1 != b1)return false;
	for (int i = 0; i < a1; i++)
	{
		if (a.arr[i] != b.arr[i])return false;
	}
	return true;
}
bool operator !=(bigint& a, bigint& b)
{
	return (!(a == b));
}
bool operator <(const bigint& a, const bigint& b)
{
	if (a.is_neg && !b.is_neg)return true;
	if (!a.is_neg && b.is_neg)return false;
	if (!a.is_neg && !b.is_neg)
	{
		if (a.arr.size()<b.arr.size())return true;
		if (a.arr.size() > b.arr.size())return false;
		for (int i = a.arr.size() - 1; i >= 0; i--)
		{
			if (a.arr[i] < b.arr[i])
				return true;
			if (a.arr[i] > b.arr[i])
				return false;
		}

	}
	if (a.is_neg && b.is_neg)
	{
		if (a.arr.size() < b.arr.size())
			return false;
		if (a.arr.size() > b.arr.size())
			return true;
		for (int i = a.arr.size() - 2; i >= 0; i--)
		{
			if (a.arr[i] > b.arr[i])
				return true;
			if (a.arr[i] < b.arr[i])
				return false;
		}
	}
	return false;
}
bool operator>(bigint& a, bigint& b)
{
	return(a != b && !(a < b));
}
bool operator<=(bigint& a, bigint& b)
{
	return(a==b || a<b);
}
bool operator>=(bigint& a, bigint& b)
{
	return(a == b || a > b);
}
bigint operator - (bigint a)
{
	a.is_neg = (!a.is_neg);
	return a;
}
bigint operator+(const bigint a, const bigint b)
{
	if (a.is_neg && !b.is_neg)
	{
		bigint t = -a;
		return (b - t);
	}
	if (!a.is_neg && b.is_neg)
	{
		bigint t1 = -a;
		return (b - t1);
	}
	if (a.is_neg && b.is_neg)
	{
		bigint t1 = -a;
		bigint t = -b;
		bigint z = (t1 + t);
		z = -z;
		return z;
	}
	
	std::vector<int>c(std::max(a.arr.size(), b.arr.size()) + 1);
	int k = 0;
	for (auto i = 0; i < c.size(); i++)
	{
		if (i < a.arr.size())k += a.arr[i];
		if (i < b.arr.size())k += b.arr[i];
		c[i] = k % 10;
		k = k / 10;
	}
	bigint q;
	q.arr = c;
	return q;
}
bigint operator-(bigint a,bigint b)
{
	if (b.is_neg)return (a + (-b));
	if (a.is_neg)
	{
		bigint z = ((-a) + b);
		z = -z;
		return z;
	}
	if (a < b)
	{
		bigint z1 = (b - a);
		z1 = -z1;
		return z1;
	}
	std::vector<int>c(std::max(a.arr.size(), b.arr.size()));
	int k = 0;
	for (auto i = 0; i < c.size(); i++)
	{
		if (i < a.arr.size())k += a.arr[i];
		if (i < b.arr.size())k -= b.arr[i];
		if (k >= 0)
		{
			c[i] = k;
			k = 0;
		}
		else
		{
			c[i] = 10 + k;
			k = -1;
		}
	}
	bigint t;
	t.arr = c;
	return t;
}
bigint toBigint(std::string &s)
{
	bigint a1;
	a1.is_neg = false;
	std::vector<int>a(s.length());
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '-')
		{
			a1.is_neg = true;
			continue;
		}
		a[i] = s[i] - '0';
	}
	reverse(a.begin(), a.end());
	a1.arr = a;
	return a1;
}
std::string toString(bigint &a)
{
	std::string s;
	reverse(a.arr.begin(), a.arr.end());
	bool u = false;
	for (int i = 0; i < a.arr.size(); i++)
	{
		if (a.arr[i] == 0 && !u)
		{
			continue;
		}
		else
		{
			u = true;
			s += a.arr[i] + '0';
		}
	}
	if (s.length() == 0)s += '0';
	else if (a.is_neg)s = '-' + s;
	return s;
}
bool toBool(bigint &a)
{
	if (a.arr.size() == 0)return false;
	return true;
}
void operator+=(bigint &a,bigint &b)
{
	a = (a + b);
}
void operator-=(bigint &a, bigint &b)
{
	a = (a - b);
}
void operator++(bigint &a)
{
	bigint t;
	t.arr.push_back(1);
	a += t;
}
void operator--(bigint &a)
{
	bigint t;
	t.arr.push_back(1);
	a -= t;
}
void extend_vec(bigint &a, bigint &b) {
	int n = std::max(a.arr.size(), b.arr.size());
	if (n % 2 == 0) n++;
	a.arr.resize(n);
	b.arr.resize(n);
}
bigint naive_mul(const bigint & x, const bigint& y) {
	bigint res;
	res.arr.resize(x.arr.size() * 2);
	for (auto i = 0; i < x.arr.size(); ++i) {
		for (auto j = 0; j < x.arr.size(); ++j) {
			res.arr[i + j] += x.arr[i] * y.arr[j];
		}
	}
	return res;
}
bigint Karatsuba(const bigint &a,const bigint &b) {
	
	bigint res;
	res.arr.resize(a.arr.size() * 2);
	if (a.arr.size() <= len_f_naive) {
		return naive_mul(a, b);
	}
	bigint xr, xl, yl, yr;
	int k = a.arr.size() / 2;
	xl.arr = { a.arr.begin(),a.arr.begin() + k };
	xr.arr = { a.arr.begin() + k,a.arr.end() };
	yl.arr = { b.arr.begin(),b.arr.begin() + k };
	yr.arr = { b.arr.begin() + k,b.arr.end() };
	bigint p1, p2, p3;
	p1 = Karatsuba(xl, yl);
	p2 = Karatsuba(xr, yr);
	bigint xlr, ylr;
	for (int i = 0; i < k; i++) {
		xlr.arr.push_back(xl.arr[i] + xr.arr[i]);
		ylr.arr.push_back(yl.arr[i] + yr.arr[i]);
	}
	p3 = Karatsuba(xlr, ylr);
	for (auto i = 0; i < a.arr.size(); i++) {
		p3.arr[i] -= p2.arr[i] + p1.arr[i];
	}
	for (auto i = 0; i < a.arr.size(); i++) {
		res.arr[i] =p2.arr[i];
	}
	for (auto i = a.arr.size(); i < 2 * a.arr.size(); ++i) {
		res.arr[i] = p1.arr[i - a.arr.size()];
	}
	for (auto i = k; i < a.arr.size() + k; ++i) {
		res.arr[i] += p3.arr[i - k];
	}
	return res;
}
void finalize(std::vector<int>& res) {
	for (auto i = 0; i < res.size()-1; ++i) {
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
}
bigint operator *(const bigint &a,const bigint &b) {
	bigint a1 = a, b1 = b;
	bool z1 = a.is_neg, z2 = b.is_neg;
	extend_vec(a1, b1);
	bigint res= Karatsuba(a1, b1);
	finalize(res.arr);
	res.is_neg = 0;
	if (!z1 && z2 || z1 && !z2)
		res.is_neg = 1 - res.is_neg;
	return res;

}
 bigint toBigint(int& a) {
	 std::string s;
	 s = std::to_string(a);
	return toBigint(s);
}
bigint operator/( bigint &a,bigint &b) 
{
	bool z1 = a.is_neg, z2 = b.is_neg;
	a.is_neg = 0;
	b.is_neg = 0;
	a.dig();
	b.dig();
	bigint temp;
	temp.is_neg = false;
	int l = 0, r = a.base;
	while (l < r - 1) {
		int m = (l + r) / 2;
		std::string s;
		temp = toBigint(m);
		temp = temp * b;
		temp.dig();
		if (temp <= a)
			l = m;
		else r = m;
	}
	bigint res = toBigint(l);
	a.is_neg = z1;
	b.is_neg = z2;
	if (!z1 && z2 || z1 && !z2)
		res.is_neg = 1 - res.is_neg;
	return res;
}
std::ostream& operator<<(std::ostream& os,  bigint& a)
{
	std::string s;
	os << toString(a);
	return os;
}
std::ostream& operator<<(std::ostream& os, bigint&& a)
{
	std::string s;
	os << toString(a);
	return os;
}
std::istream& operator>>(std::istream& os, bigint& a)
{
	std::string s;
	os >> s;
	a = toBigint(s);
	return os;
}
