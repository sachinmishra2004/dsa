class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int>pq;
        int sum =0;
        for(int i =0; i<n; i++){
            pq.push(piles[i]);
            sum+=piles[i];
        }
        for(int i =1; i<=k; i++){
            int max_ele = pq.top();
            pq.pop();

            int remove = max_ele/2;
            sum-=remove;
            max_ele-=remove; // attack

            pq.push(max_ele);
        }
        return sum;
    }
};