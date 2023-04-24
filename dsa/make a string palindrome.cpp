class Solution {
public:
    int n;
    int t[501][501];
    int slove(string&s, int i, int j){
        if(i>=j)
           return 0;
        if(t[i][j]!=-1)
          return t[i][j];
        if(s[i]==s[j])
          return t[i][j] =  slove(s, i+1, j-1);

        return t[i][j] = 1+min(slove(s, i+1,j), slove(s, i,j-1));
    }
    int minInsertions(string s) {
    n =s. length();
    memset(t, -1, sizeof(t));
    return slove(s, 0, n-1);
    }
};