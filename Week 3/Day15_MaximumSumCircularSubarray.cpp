class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int lMax = 0, gMax = INT_MIN, gMin = INT_MAX, lMin = 0, sum = 0, i = 0;
        while(i < A.size()) {
            sum += A[i];
            lMax += A[i];
            lMin += A[i];
            gMax = max(gMax, lMax);
            gMin = min(gMin, lMin);
            if(lMax < 0) {
                lMax = 0;    
            }
            if(lMin > 0) {
                lMin = 0;
            }
            i++;
        }
        return gMax < 0 ? gMax : max(gMax, sum - gMin);
    }
};