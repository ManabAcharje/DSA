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
    typedef unsigned long long  ull;
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,ull>>q;
       
        q.push({root,0});
        int ans = 1;

        while (!q.empty()) {
            int sz = q.size();

            // first not_null node is left_most;
            bool left_found = false;
            int left_most = 0;
            int right_most = 0;
            for (int x = 0; x < sz; x++) {
                
                auto [node, i] = q.front();
                q.pop();
                // cout<<"pooped "<<node->val<<" "<<i<<"\n";
                if (node->left){
                    q.push({node->left, 2 * i + 1});
                   
                    right_most = 2*i + 1;

                    if(!left_found){
                        left_found = true;
                        left_most = 2 * i + 1;
                    }
                }
                    
                if (node->right){
                    q.push({node->right, 2 * i + 2});
                    
                    right_most = 2*i +2;
                    if(!left_found){
                        left_found = true;
                        left_most  = 2*i + 2;
                    }
                }
                
            }
            int curr = right_most- left_most + 1;
            // cout<<curr<<endl;
            ans = max(ans,curr);
        }
        return ans;
    }
};