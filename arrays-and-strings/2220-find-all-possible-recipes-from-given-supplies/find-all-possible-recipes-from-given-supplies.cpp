class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // topological sort
        // to creater bread  -> i need to have yeast and flour -> do i have them
        // how to check -> check them in supplies -> if all present  then add
        // item to ans;

        // first we can do with brute for

        unordered_set<string> seen;
        for (string& supply : supplies)
            seen.insert(supply);
        vector<string> ans;
        int n = recipes.size();
        int count = n;

        while (count--) {
            int idx = -1;
            for (auto& recipe : recipes) {
                // do i have all the the ingredients
                idx++;
                if (seen.count(recipe))
                    continue;
                bool possible = true;
                for (auto& ingredient : ingredients[idx]) {
                    if (!seen.count(ingredient)) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    ans.push_back(recipe);
                    seen.insert(recipe);
                }
              
            }
        }
        return ans;
    }
};