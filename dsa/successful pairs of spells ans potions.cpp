class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      int m = spells.size();
      int n = potions.size();

      sort(begin(potions),  end(potions));
      int maxpotion = potions[n-1];
      vector<int>ans;
      for(int i =0; i<m; i++){
          int spell = spells[i];
          //minterm*spell>= success;
          long long minpotion = ceil((1.0*success)/(spell));
          if(minpotion> maxpotion){
              ans.push_back(0);
              continue;
            }
            int index = lower_bound(begin(potions), end(potions), minpotion)- begin(potions);
            ans.push_back(n-index);
        }
        return ans;
    }
};