class Solution {
public:
               // {sum ,{i,j}};
    typedef pair<int, pair<int, int>>p;//const define kardiya
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p, vector<p>>pq; // max heap;
        int m = nums1.size();
        int n = nums2.size();

        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){ // k elements hum push karege;
                    pq.push({sum, {i,j}});
                }
                else if(pq.top().first > sum ){
                    pq.pop();
                    pq.push({sum, {i,j}}); // naya sum dal do;
                }
                else{
                    break; // koiki humaine further nhi jana 
                }
            }
        }
        vector<vector<int>>result;
        while(!pq.empty()){ //sare mininmu hoge elemnets in pq main
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first; // i
            int j = temp.second.second; //j;

            result.push_back({nums1[i], nums2[j]});

        }
        return result;
    }
};