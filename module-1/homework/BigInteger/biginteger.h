class bigint
{
	public: 
	int base = 1e9;
	std::vector<int>arr;
	bool is_neg;
	friend bigint operator - (bigint a);
	friend bigint operator +( bigint a,  bigint b);
	friend bigint operator -( bigint a,  bigint b);
	friend bigint operator *(const bigint &a,const bigint &b);
	friend bigint operator /( bigint &a,  bigint &b);
	friend bool operator <(bigint &a, bigint &b);
	friend bool operator >(bigint &a, bigint &b);
	friend bool operator <=(bigint &a, bigint &b);
	friend bool operator >=(bigint &a, bigint &b);
	friend bool operator ==(bigint &a, bigint &b);
	friend bool operator !=(bigint &a, bigint &b);
	friend std::ostream& operator <<(std::ostream& os, bigint& a);
	friend std::ostream& operator <<(std::ostream& os, bigint&& a);
	friend std::istream& operator >>(std::istream& os, bigint& a);
	friend bigint toBigint(std::string& s);
	friend std::string toString(bigint &a);
	friend bigint toBigint(int& a);
	friend bool toBool(bigint &a);
	void dig() {
		for (int i = arr.size() - 1; i >= 0; i--) {
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
