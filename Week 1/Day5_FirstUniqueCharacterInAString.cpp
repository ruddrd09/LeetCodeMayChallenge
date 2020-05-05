class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        for(int i=0;i<s.size();i++) {
            m[s[i]].first = i;
            m[s[i]].second++;
        }
        int ans = INT_MAX;
        for(auto i: m) {
            if(i.second.second == 1) {
                ans = min(ans, i.second.first);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};