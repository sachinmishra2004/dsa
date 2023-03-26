cycle detection direct graph using dfs 

class Solution {
public:
    int result= -1;
    void dfs(int u, vector<bool>&visited, vector<bool>&inRecursion, vector<int>&dist, vector<int>&edges){
        if(u!=-1){
            visited[u] = true;
            inRecursion[u] = true;

            int v = edges[u];
            if(v!=-1 && !visited[v]){
                dist[v] = dist[u]+1;
                dfs(v,visited, inRecursion,dist, edges );
            } 
            else if(v!=-1 && inRecursion[v]==true){ // cycle
            result = max(result, dist[u]-dist[v]+1);
            }
            inRecursion[u] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n= edges.size();

        vector<bool>visited(n,false);
        vector<bool>inRecursion(n,false);

        vector<int>dist(n,1);
        for(int i =0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, inRecursion, dist, edges);
            }
        }
        return result;
    }
};