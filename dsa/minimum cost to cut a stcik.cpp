//using recursion and memorization
class Solution {
public:
    int t[103][103];
    int slove(vector<int>&cuts, int l, int r){
        if(r-l < 2){ 
            return 0;
        }
        if(t[l][r]!= -1){
            return t[l][r];
        }
        int result = INT_MAX;

        for(int index = l+1; index<=r-1; index++){//{l, c1, r}
            int cost = (cuts[r] - cuts[l]) + slove(cuts ,l, index) + slove(cuts, index, r);

            result = min(result, cost);
        } 
        return t[l][r] =  result;
    }
    int minCost(int n, vector<int>& cuts) {
        //step 1 - sorting
        sort(begin(cuts), end(cuts));
        // step 2
        cuts.insert(begin(cuts), 0); //0 starting point of stick;
        cuts.push_back(n); // ending point of the stick
        memset(t, -1, sizeof(t));
        return slove(cuts, 0, cuts.size()-1);

    }
};