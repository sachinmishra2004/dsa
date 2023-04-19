class Solution {
public:
    int maxpath =0;
    void slove(TreeNode* root, int steps, bool goleft){
        if(root==NULL)
          return ;
        maxpath = max(maxpath,steps);
        if(goleft==true){ ///left ke liye bola toh chalegaye
            slove(root->left, steps+1, false);
            slove(root->right, 1, true);
        }
        else{ //right main jana hai
            slove(root->right, steps+1, true);
            slove(root->left, 1, false);

        }
    }
    int longestZigZag(TreeNode* root) {
        slove(root, 0, true);
        slove(root, 0, false);

        return maxpath;
    }
};