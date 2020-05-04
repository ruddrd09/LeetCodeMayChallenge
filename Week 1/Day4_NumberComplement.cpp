class Solution {
public:
    int findComplement(int num) {
        int x[32] = {0};
        int z = 0;
        while(num) {
            x[z] = !(num%2);
            num /= 2;
            z++;
        }
        int n = 0;
        for(int i=0;i<31;i++) {
            n += x[i]*pow(2, i);
        }
        return n;
    }
};