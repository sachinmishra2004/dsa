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

class Solution {
public:
    
    //this function is solution of House robber I. We just use it to solve House Robber II
    int solve(vector<int>& nums, int l, int r) {
        
        int prevPrev = 0, prev = 0;
        
        for(int i = l; i<=r; i++) {
            int skip = prev;
            int take = nums[i] + prevPrev;
            
            int temp = max(skip, take);
            
            prevPrev = prev;
            prev     = temp;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        int take_first_house = solve(nums, 0, n-2);
        
        int skip_first_house = solve(nums, 1, n-1);
        
        
        return max(take_first_house, skip_first_house);
    }
};

//Approach-2 (Using Bottom Up similar to House Robber-1 and just taking two cases
/*
    Case-1 (Take from 1st House - Hence skip the last house)
    Case-2 (Take from 2nd House - Hence take the last house)
*/
class Solution {
public:
    int n;
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1, 0);
        //t[i] = Max money gained from i houses
        
        int result1 = 0;
        int result2 = 0;
        
        //Case-1 (Take from 1st House - Hence skip the last house)
        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result1 = t[n-1];
        
        t.clear();
        //Case-2 (Take from 2nd House - Hence take the last house)
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result2 = t[n];
        
        return max(result1, result2);
        
    }
};
