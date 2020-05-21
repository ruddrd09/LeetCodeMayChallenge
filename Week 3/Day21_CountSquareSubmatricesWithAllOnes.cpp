class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        int dp[m][n];
        int total = 0;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } else if(matrix[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
                total += dp[i][j];
            }
        }
        return total;
    }
};