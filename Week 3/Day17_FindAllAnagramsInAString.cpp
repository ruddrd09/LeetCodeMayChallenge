class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m;
        for(auto i: p) {
            m[i]++;
        }
        vector<int> a;
        int l = 0, r = 0;
        int z = p.size();
        int n = s.size();
        int count = p.size();
        while(r < n) {
            if(m[s[r]] >= 1) {
                count--;
            }
            m[s[r]]--;
            r++;
            if(count == 0) {
                a.push_back(l);
            }
            if(r-l == z && m[s[l]] >= 0) {
                count++;
            }
            if(r-l == z) {
                m[s[l]]++;
                l++;
            }
        }
        return a;
    }
};