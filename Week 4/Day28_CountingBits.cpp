class Solution { // Solution 1
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for(int i=1;i<=num;i++) {
            ans[i] = ans[i>>1] + (i&1); // Recurrence relation -> f(i) = f(i/2) + i%2
        }
        return ans;
    }
};

class Solution { // Solution 2
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        int f = 0;  
        for(int i=1;i<=num;i++) {
            if((i & (i-1)) == 0) {
                f = i;  // f has the nearest power of 2
            }
            ans[i] = ans[i-f] + 1;
        }
        return ans;
    }
};