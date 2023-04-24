class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    priority_queue<int>pq;

    for(int&stone: stones){
        pq.push(stone);
    }
    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if(x!=y)
        pq.push(abs(x-y));
    }
    return pq.top();
   
    }     
};

##### 2
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1)
        {
            sort(stones.begin(),stones.end());
            
            int a = stones.back(); stones.pop_back();
            int b = stones.back(); stones.pop_back();

            stones.push_back(abs(a-b));
        }
        
        return stones[0];
    }     
};
