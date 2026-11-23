class RangeModule {
public:
    set<pair<int, int>> st;
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = st.begin();
        while (it != st.end()) {
            int l = it->first;
            int r = it->second;

            if (r < left || l > right) {
                ++it;
            } else {
                left = min(left, l);
                right = max(right, r);
                it = st.erase(it);
            }
        }
        st.insert({left, right});
    }

    bool queryRange(int left, int right) {
        auto it = st.begin();
        while (it != st.end()) {
            int l = it->first;
            int r = it->second;

            if (l <= left && right <= r) {
                return true;
            }
            ++it;
        }
        return false;
    }

    void removeRange(int left, int right) {
        vector<pair<int, int>> add_back;
        auto it = st.begin();
        while (it != st.end()) {
            int l = it->first;
            int r = it->second;

            if (r <= left || l >= right) {
                ++it;
            } else {
                it = st.erase(it);
                if (l < left)
                    add_back.push_back({l, left});
                if (r > right)
                    add_back.push_back({right, r});
            }
        }
        for (auto p : add_back) {
            st.insert(p);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */