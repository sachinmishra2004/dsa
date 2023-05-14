class Solution {
public:
    int n;
    long long slove(int i,vector<vector<int>>& questions,vector<long long>&t){
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1)
                return t[i];
        //agar lenge toh hum | => points  +      (0, brainpower_points +1 ){because for skip purpose in this case};
        long long taken = questions[i][0] + slove(i+ questions[i][1] + 1,questions,t);
        long long not_taken = slove(i+1, questions, t);
       
       return t[i] = max(taken, not_taken);
    }
    long long mostPoints(vector<vector<int>>& questions) {
         n = questions.size();
        // ek hi vector lenge for momozition ke liye because ek hi variable change ho raha 
        vector<long long>t(n+1, -1);
        return slove(0,questions,t);
    }
};