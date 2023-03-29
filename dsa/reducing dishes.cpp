class Solution {
public:
    int n;
    int dp[501][501];
    int slove(vector<int>&satisfaction,int i, int t){
        if(i>=n)
        return 0;
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int include = satisfaction[i]*t+ slove(satisfaction,i+1, t+1);
        int exclude = slove(satisfaction, i+1, t);

        return dp[i][t] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
         n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp, -1, sizeof(dp));
        return slove(satisfaction, 0,1);
    }
};