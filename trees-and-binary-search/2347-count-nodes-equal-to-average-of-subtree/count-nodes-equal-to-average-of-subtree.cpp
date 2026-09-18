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
    int count;
    pair<int,int> solve(TreeNode *root){

        if(root == nullptr)return {0,0};
        
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);

        int total = root->val + l.first +r.first;
        int no_nodes = 1 + l.second + r.second;

        int avg = total / no_nodes;
        if(root->val == avg )count++;

        return {total,no_nodes};

    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;

        auto res = solve(root);

        return count;
    }
};