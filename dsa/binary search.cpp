// binary search apporoach with time complexity O(log n);
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

using recursive apporaoch
class Solution {
public:
    int slove(vector<int>& nums,int s, int e, int target){
        if(s>e)
        return -1;
        int mid = s+(e-s)/2;
        if(nums[mid]== target)
        return mid;
        else if(nums[mid]< target){
            return slove(nums, mid+1, e, target);
        }
        else if(nums[mid]> target){
           return  slove(nums, s, mid-1, target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
     int n = nums.size();
     return slove(nums, 0, n-1, target);
    }
};
