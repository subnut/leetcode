#define maximumWealth max_wealth
int max_wealth(int **accounts, int customers, int *banks) {
	int max = 0;
	int cur = 0;
	for (int cust = 0; cust < customers; cust++) {
		cur = 0;
		for (int bank = 0; bank < *banks; bank++)
			cur += accounts[cust][bank];

		if (cur > max)
			max = cur;
	}
	return max;
}
