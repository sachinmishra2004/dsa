class Solution {
public: // time complexity  = o(32^n);
    int singleNumber(vector<int>& nums) {
      unordered_map<int,int> mp;
      for(auto temp : nums){
          mp[temp]++;
        }   
        for(auto val : mp){
            int val1 = val.first;
            int freq = val.second;
            if(freq ==1){
                return val1;
            } 
        } 
        return -1;
    }

};