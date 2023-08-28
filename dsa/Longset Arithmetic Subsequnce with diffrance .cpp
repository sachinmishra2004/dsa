class Solution {
public:
    int n;
    int D;
    int t[100001];
    int slove(int idx, vector<int>&arr){
        int result =0;
        if(t[idx]!= -1){
            return t[idx];
        }
        for(int j = idx+1; j<n; j++){
            int prev= arr[idx];
            int curr = arr[j];
            if(curr- prev ==D){
                result = max(result, 1+ slove(j, arr));
            }
        }
        return t[idx]= result;
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        D = difference;
        n = arr.size();
        int result = 0;
        memset(t, -1, sizeof(t));
        for(int i = 0; i<n; i++){
            result = max(result, 1+ slove(i,arr));
        }
        return result;
    }
};