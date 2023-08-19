class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int prefixsum =0;
        int ans = INT_MIN;
        for(int i =1; i<=n; i++){
           prefixsum+= gain[i-1];
           ans = max(ans, prefixsum); 
        }
        if(ans < 0){
            return 0;
        }
        return ans;
    }
};