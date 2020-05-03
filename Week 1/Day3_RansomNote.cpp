class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m(26);
        for(char i: magazine) {
            m[i]++;
        }
        for(char i: ransomNote) {
            if(!m[i]) {
                return 0;
            } else {
                m[i]--;
            }
        }
        return 1;
    }
};