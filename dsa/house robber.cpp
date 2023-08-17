class Solution {
public:
    int t[101];
    int slove(vector<int>&nums, int i, int n){
        if(i> n)
            return 0;
        if(t[i] !=-1)
            return t[i];
        int steal = nums[i] + slove(nums, i+2, n); //steals ith house and moves to i+2(becuase we cant steal house);
        int skip = slove(nums, i+1, n); // skip this house now we can move to adjecnt house;

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) // cori karo nikal jayo
            return nums[0];
        if(n==2){ // max lege
            return max(nums[0], nums[1]);
        }
        memset(t , -1, sizeof(t));
        //case 1 = take first house 0th index wala house;

        int take_first_oth_index = slove(nums, 0, n-2);
        memset(t, -1, sizeof(t));
        // case2 
         int take_first_1th_index = slove(nums, 1,n-1);

         return max(take_first_oth_index, take_first_1th_index);
    }
};