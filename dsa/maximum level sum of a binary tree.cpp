//using bfs

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxsum = INT_MIN;
        int resultlevel = 0;
        int currlevel = 1; // it is mention in questions

        queue< TreeNode* > que;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            int sum  = 0;
            //treversing all the elemnets of curr level;
            while(n--){
                TreeNode*temp = que.front();
                que.pop();

                sum += temp->val;

                if(temp->left!=NULL)
                    que.push(temp->left);
                if(temp->right!= NULL)
                    que.push(temp->right);
            }
            if(sum > maxsum){
                    maxsum = sum;
                    resultlevel = currlevel;
            }
             currlevel++;
        }
        return resultlevel;

    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> mp;
    void dfs(TreeNode* root, int currlevel){
        if(!root)
            return;
        mp[currlevel]+= root->val;

        dfs(root->left, currlevel+1);
        dfs(root->right, currlevel+1);

    }
    int maxLevelSum(TreeNode* root) {
       mp.clear();

       dfs(root, 1);

       int maxsum = INT_MIN;
       int result = 0;

       for(auto it : mp){
           int level = it.first;
           int sum = it.second;

           if(sum> maxsum){
           maxsum = sum;
           result = level;
           }
       }
      
       return result;
    }
};