/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    unordered_map < TreeNode*, vector<TreeNode*>>adj;
    void buildGraph(TreeNode* root) {
        if (root == nullptr)
            return;

        if (root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            buildGraph(root->left);
        }
        if (root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            buildGraph(root->right);
        }
    }
    void bfs(TreeNode* target, int k) {
     unordered_set<TreeNode*>visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited.insert(target);

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == k) {
                result.push_back(node->val);
                continue;
            }

            for (TreeNode* neighbor : adj[node]) {

                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, dist + 1});
                }
            }
        }
    }
    vector<int> distanceK(TreeNode * root, TreeNode * target, int k) {
        buildGraph(root);
        bfs(target, k);
        return result;
    }
};