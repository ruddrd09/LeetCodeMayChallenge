class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[major] == nums[i]) {
                count++;
            } else {
                count--;
                if(count == 0) {
                    major = i;
                    count++;
                }
            }
        }
        return nums[major];
    }
};