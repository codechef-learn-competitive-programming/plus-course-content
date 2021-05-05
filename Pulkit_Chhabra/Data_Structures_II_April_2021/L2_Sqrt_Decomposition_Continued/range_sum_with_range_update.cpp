class NumArray {
	int n, b, sz;
	vector<int> sum, arr, lazy; //sum for each block

public:
	NumArray(vector<int>& nums)
	{
		n = nums.size();
		b = sqrt(n);
		sz = (n + b - 1) / b;

		sum.assign(sz, 0);
		lazy.assign(sz, 0);
		arr = nums;

		for (int i = 0; i < n; ++i)
			sum[i / b] += arr[i];
	}

	void update(int i, int val) // = val -> += val
	{
		sum[i / b] += val;
		arr[i] += val;
	}

	void update(int l, int r, int val)
	{
		int l_block = l / b, end_l = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, start_r = r_block * b;

		for (int i = l; i <= min(r, end_l); ++i)
			update(i, val);

		if (l_block != r_block)
		{
			// update elements in R_block
			for (int i = start_r; i <= r; ++i)
				update(i, val);

			// update lazy of intermediate blocks
			for (int block = l_block + 1; block < r_block; ++block)
				lazy[block] += val;
		}
	}

	int sumRange(int l, int r)
	{
		int ans = 0;

		int l_block = l / b, end_l = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, start_r = r_block * b;

		// add elements from L_block
		for (int i = l; i <= min(r, end_l); ++i)
			ans += arr[i] + lazy[l / b];

		if (l_block != r_block)
		{
			// add elements from R_block
			for (int i = start_r; i <= r; ++i)
				ans += arr[i] + lazy[r / b];

			// add sum_values of intermediate blocks
			for (int block = l_block + 1; block < r_block; ++block)
				ans += sum[block] + b * lazy[block];
		}

		return ans;
	}
};
