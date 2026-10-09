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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        //print the right most node  from graph
        if(root== nullptr)return {};
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i<= sz-1 ; i++){
                if(i == sz -1){
                    ans.push_back(q.front()->val);
                }
                TreeNode* u = q.front();
                q.pop();
                if(u->left)q.push(u->left);
                if(u->right)q.push(u->right);
                

            }

        }
        return ans;
    }

};