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
    unordered_map<TreeNode*, int>memo;
    int solve(TreeNode* root) {
       if(root == nullptr)return 0;
       //we didn't take root
       if(memo.count(root))return memo[root];

       int opt1 = (solve(root->left)+solve(root->right));
       int opt2 =root->val;
       if(root->left)opt2+=solve(root->left->left)+solve(root->left->right);
       if(root->right)opt2+=solve(root->right->left)+solve(root->right->right);



        return memo[root]=max(opt1,opt2);
    }
    int rob(TreeNode* root) {
        
        return solve(root);
    }
};