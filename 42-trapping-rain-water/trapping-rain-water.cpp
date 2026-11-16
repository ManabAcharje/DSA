class Solution {
public:
    int solve(vector<int> height) {
        int n = height.size();
        if (n == 0) return 0;
        
        height.push_back(INT_MAX);
        vector<int> pref(n);
        pref[0] = height[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + height[i];
        }
        
        vector<int> ngr(n);
        stack<int> st;
        st.push(n);
        
        for(int i = n - 1; i >= 0; i--) {
            int curr = height[i];
            while(!st.empty() && height[st.top()] < curr) {
                st.pop();
            }
            ngr[i] = st.top();
            st.push(i); 
        }
        
        int j = 0;
        int ans = 0;
        while(j < n) {
           int idx = ngr[j];
           if(idx == n) {
               j++;
           } else {
                ans += height[j] * (idx - j);
                int blocks = (idx > 0 ? pref[idx-1] : 0) - (j >= 1 ? pref[j-1] : 0); 
                ans -= blocks;
                j = idx;
           }
        }
        return ans;
    }
    
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int max_idx = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] > height[max_idx]) {
                max_idx = i;
            }
        }
        
        vector<int> left_part(height.begin(), height.begin() + max_idx + 1);
        vector<int> right_part(height.begin() + max_idx, height.end());
        reverse(right_part.begin(), right_part.end());
        
        return solve(left_part) + solve(right_part);
    }
};