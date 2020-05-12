class Solution { //Solution 1
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if((mid == nums.size()-1 || nums[mid] != nums[mid+1]) && (mid == 0 || nums[mid] != nums[mid-1])) {
                return nums[mid];
            } else if((nums[mid] == nums[mid-1] && mid % 2 == 0) || (nums[mid] == nums[mid+1] && mid % 2 == 1)) {
                r = mid-1;
            } else {
                l = mid+1; 
            }
        }
        return -1;
    }
};

class Solution { //Solution 2
public:
    int bsearch(vector<int>& nums, int l, int r) {
        if(l > r) {
            return INT_MAX;
        }
        int mid = l + (r-l)/2;
        if((mid == 0 || nums[mid] != nums[mid-1]) && (mid == nums.size()-1 || nums[mid] != nums[mid+1])) {
            return nums[mid];
        }
        int left = bsearch(nums, mid+1, r);
        int right = bsearch(nums, l, mid-1);
        return left == INT_MAX ? right : left;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        return bsearch(nums, 0, nums.size()-1);
    }
};