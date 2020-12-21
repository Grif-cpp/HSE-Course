class BigInteger
{
private:
std::vector<int>arr;
	bool is_neg;
public:
	int base = 1e9;
	friend BigInteger operator - (BigInteger a);
	friend BigInteger operator +(const BigInteger a,const BigInteger b);
	friend BigInteger operator -( BigInteger a,  BigInteger b);	
	friend BigInteger Karatsuba(const BigInteger &a, const BigInteger &b);
	friend void extend_vec(BigInteger &a, BigInteger &b);
	friend BigInteger naive_mul(const BigInteger & x, const BigInteger& y);
	friend BigInteger operator *(const BigInteger &a,const BigInteger &b);
	friend BigInteger operator/( BigInteger &a,  BigInteger &b);
	friend bool operator <(const BigInteger &a,const BigInteger &b);
	friend void operator ++(BigInteger &a);
	friend void operator --(BigInteger &a);
	friend bool operator >(const BigInteger &a, const BigInteger &b);
	friend bool operator <=(const BigInteger &a, const BigInteger &b);
	friend bool operator >=(const BigInteger &a, const BigInteger &b);
	friend bool operator ==(const BigInteger &a, const BigInteger &b);
	friend bool operator !=(const BigInteger &a, const BigInteger &b);
	friend std::ostream& operator <<(std::ostream& os, BigInteger& a);
	friend std::ostream& operator <<(std::ostream& os, BigInteger&& a);
	friend std::istream& operator >>(std::istream& os, BigInteger& a);
	friend BigInteger toBigint(std::string& s);
	friend std::string toString(BigInteger &a);
	friend BigInteger toBigint(int& a);
	friend bool toBool(BigInteger &a);
	void resizer() {
		for (auto i = arr.size() - 1; i >= 0; i--) {
			if (arr[i] != 0) {
				arr.resize(i + 1);
				break;
			}
		}
	}
	void shift_right() {
		if (arr.size() == 0) {
			arr.push_back(0);
			return;
		}
		arr.push_back(arr[arr.size() - 1]);
		for (size_t i = arr.size() - 2; i > 0; i--) {
			arr[i] = arr[i - 1];
			arr[0] = 0;
		}
	}
};
