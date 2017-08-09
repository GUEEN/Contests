typedef long long int64;
// const int64 M = 1000000007;

class matrix
{
public:
	matrix(int n) : n(n), A(n, vector<int64>(n)) {}
	int64& operator()(int64 i, int64 j) { return A[i][j]; }
	int64 operator()(int64 i, int64 j) const { return A[i][j]; }
	int64 size() const { return n; }

private:
	int n;
	vector<vector<int64>> A;
};


matrix id(int64 n)
{
	matrix I(n);
	for (int i = 0; i < n; i++)
		I(i, i) = 1;
	return I;
}

matrix operator *(const matrix& A, const matrix& B)
{
	int64 n = A.size();
	matrix C(n);

	for (int64 i = 0; i < n; i++)
		for (int64 j = 0; j < n; j++)
			for (int64 k = 0; k < n; k++)
			{
				C(i, j) += A(i, k) * B(k, j); // % M;
				//C(i, j) %= M;
			}
	return C;
}

matrix operator ^(const matrix& A, int64 m)
{
	int64 n = A.size();
	matrix R = id(n);
	matrix B = A;
	while (m)
	{
		if (m & 1)
		{
			m--;
			R = R * B;
		}
		else
		{
			m >>= 1;
			B = B * B;
		}

	}
	return R;
}