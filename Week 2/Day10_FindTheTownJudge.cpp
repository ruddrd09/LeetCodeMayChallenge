class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustee(N+1);
        vector<int> trusted(N+1);
        for(auto i: trust) {
            trustee[i[0]]++;
            trusted[i[1]]++;
        }
        for(int i=1;i<=N;i++) {
            if(trustee[i] == 0 && trusted[i] == N-1) {
                return i;
            }
        }
        return -1;
    }
};