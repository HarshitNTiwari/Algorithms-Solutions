#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& arr, int i, int j, vector<vector<int>>& dp) {
	int N = arr.size();
	int M = arr[0].size();

	if (dp[i][j] != -1)
		return dp[i][j];

	vector<int> rowNbr = {1, -1, 0, 0};
	vector<int> colNbr = {0, 0, 1, -1};

	int ans = 0;
	for (int k = 0; k < 4; k++) {
		if ((i + rowNbr[k]) < 0 || (j + colNbr[k]) < 0 || (i + rowNbr[k]) > (N - 1) || (j + colNbr[k]) > (M - 1))
			continue;
		if (arr[i + rowNbr[k]][j + colNbr[k]] > arr[i][j]) {
			ans = max(ans, solve(arr, i + rowNbr[k], j + colNbr[k], dp));
		}
	}
	return dp[i][j] = 1 + ans;
}

int solveMain(vector<vector<int>>& arr, int N, int M) {
	if (N == 1 && M == 1)
		return 1;
	vector<vector<int>> dp(N, vector<int>(M, -1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			solve(arr, i, j, dp);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}

int main()
{
	int T; cin >> T;
	while (T) {
		int N; int M;
		cin >> N >> M;
		vector<vector<int>> arr(N, vector<int>(M, -1));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}
		cout << solveMain(arr, N, M) << endl;
		T--;
	}
	return 0;
}