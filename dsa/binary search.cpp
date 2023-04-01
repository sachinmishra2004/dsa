class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int s =0;
      int e = n-1;
      while(s<=e){
          int mid = s+(e-s)/2;
          if(nums[mid]== target)
          return mid;
          if(nums[mid]< target){
              s = mid+1;
            }
          if(nums[mid]> target){
              e = mid-1;
            }

        }
        return -1;
    }
};