class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int j = 0;
        for(auto i: num) {
            while(!s.empty() && s.top() > i && j < k) {
                s.pop();
                j++;   
            }
            s.push(i);
        }
        num.clear();
        while(!s.empty()) {
            num += s.top();
            s.pop();
        }
        int i = num.size()-1;
        while(i >= 0 && num[i] == '0') {
            num.pop_back();
            i--;
        }
        reverse(num.begin(), num.end());
        while(num.size() && j < k) {
            num.pop_back();
            j++;
        }
        if(!num.size()) {
            num += '0';
        }
        return num;
    }
};