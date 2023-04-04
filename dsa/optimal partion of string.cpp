class Solution {
public:
    int partitionString(string s) {
        vector<int>lastseen(26, -1);
        int n = s.size();
        int count =0;
        int substringstart = 0;
        for(int i =0; i<n; i++){
            char ch = s[i];
            // index nikalene ki vidhi
            if(lastseen[ch-'a'] >= substringstart){
                count++; // yani string humain todin padegi 
                substringstart = i;
            }
            lastseen[ch-'a'] = i;//yani humne last kaha dekha ok
        }
        return count+1;

    }
};