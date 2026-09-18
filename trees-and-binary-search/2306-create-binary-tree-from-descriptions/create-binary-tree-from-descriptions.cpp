class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;// if a node is never become child  then this will be our root
        

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);

            if (!mp.count(child))
                mp[child] = new TreeNode(child);

            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            childSet.insert(child);
        }

        for (auto &[val, node] : mp) {
            if (!childSet.count(val))
                return node;
        }

        return nullptr;
    }
};