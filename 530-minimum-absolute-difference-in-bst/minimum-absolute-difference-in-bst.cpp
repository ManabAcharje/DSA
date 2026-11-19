/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int min_diff = INT_MAX;
    int prev_val = INT_MAX;

    void solve(TreeNode* root) {
        if (root == nullptr)
            return;
        solve(root->left);
        int curr_val = root->val;

        int curr_diff = abs(prev_val - curr_val);
        min_diff=  min(min_diff,curr_diff);
        prev_val = curr_val;

        solve(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return min_diff;
    }
};