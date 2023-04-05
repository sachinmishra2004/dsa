class Solution {
public:
    bool isvalid(vector<int>&nums, int mid_max,int n){
        vector<long long> arr(begin(nums), end(nums));
        for(int i =0; i<n-1; i++){ //right se 1 kam bar chalega ok
            if(arr[i]> mid_max){
                return false;
            }
            long long buffer = mid_max - arr[i]; // find the no of the steps 
            arr[i+1] = arr[i+1]-buffer;
        }
        return arr[n-1] <= mid_max;
    }
  
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int startL = 0;
        int endR = *max_element(begin(nums), end(nums));
        int result;
        while(startL<=endR){
            int mid_max = startL+(endR- startL)/2;
            if(isvalid(nums, mid_max, n)){
                result = mid_max;
                endR = mid_max-1;
            }
            else{
                startL = mid_max+1;
            }
        }
        return result;
    }
};