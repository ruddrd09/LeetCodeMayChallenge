class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        for(auto i: s1) {
            m[i]++;
        }
        int l = 0, r = 0;
        int z = s1.size();
        int n = s2.size();
        int count = s1.size();
        while(r < n) {
            if(m.find(s2[r]) != m.end()) {
                m[s2[r]]--;
                if(m[s2[r]] > -1) {
                    count--;   
                }
            }
            r++;
            if(count == 0) {
                return 1;
            }
            if(r-l == z && m.find(s2[l]) != m.end()) {
                m[s2[l]]++;
                if(m[s2[l]] > 0) {
                    count++;   
                }
            }
            if(r-l == z) {
                l++;
            }
        }
        return 0;
    }
};