class Solution {
public:
    typedef unsigned long long ll;
    
    void DFS(TreeNode* root, ll d, int level, vector<int>& arr, ll& maxWidth) {
        if(!root)
            return;
        
        if(level == arr.size()) {
            arr.push_back(d);
        } else {
            maxWidth = max(maxWidth, d-arr[level]+1);
        }
        
        DFS(root->left, 2*d+1, level+1, arr, maxWidth);
        DFS(root->right, 2*d+2, level+1, arr, maxWidth);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   
            return 0;
        
        ll maxWidth = 1;
        vector<int> arr;
        DFS(root, 0, 0, arr, maxWidth);
        return maxWidth;
    }
};