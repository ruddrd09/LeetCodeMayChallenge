class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int m = A.size();
        int n = B.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(A[i][1] < B[j][1]) {
                if(A[i][1] >= B[j][0]) {
                    ans.push_back({max(A[i][0], B[j][0]), A[i][1]});
                }
                i++;
            } else if(A[i][1] >= B[j][1]) {
                if(B[j][1] >= A[i][0]) {
                    ans.push_back({max(A[i][0], B[j][0]), B[j][1]});
                }
                j++;
            }
        }
        return ans;
    }
};