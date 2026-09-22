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
    int ans;
    int solve(TreeNode* root){
        if(root == nullptr)return 0;

        

        int left = max(0, solve(root->left));
        cout<<"left  = "<<left<<"\n";
    

        int right = max(0, solve(root->right));
        cout<<"right = "<<right<<"\n";
     
        int temp = root->val + left + right;
        cout<<"temp = "<<temp<<"\n";
        

        ans = max(ans,temp);
        cout<<"ans = "<<ans<<"\n";
        
        return root->val + max(left,right);
        
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        int x =  solve(root);
        return ans;
    }
};