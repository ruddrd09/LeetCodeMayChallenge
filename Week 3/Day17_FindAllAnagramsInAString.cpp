class Solution { //Solution 1
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
            if(m.find(s[r]) != m.end()) {
                m[s[r]]--;
                if(m[s[r]] > -1) {
                    count--;   
                }
            }
            r++;
            if(count == 0) {
                a.push_back(l);
            }
            if(r-l == z && m.find(s[l]) != m.end()) {
                m[s[l]]++;
                if(m[s[l]] > 0) {
                    count++;   
                }
            }
            if(r-l == z) {
                l++;
            }
        }
        return a;
    }
};

class Solution { //Solution 2
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