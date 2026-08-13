class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {

            bool alive = true;

            while (!ans.empty() && ans.back() > 0 && x < 0) {

                if (abs(ans.back()) < abs(x)) {
                    // Previous asteroid explodes
                    ans.pop_back();
                }
                else if (abs(ans.back()) == abs(x)) {
                    // Both explode
                    ans.pop_back();
                    alive = false;
                    break;
                }
                else {
                    // Current asteroid explodes
                    alive = false;
                    break;
                }
            }

            if (alive) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};