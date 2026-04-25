typedef pair<int,int> P;

class MovieRentingSystem {
public:
    unordered_map<int, set<P>> available;          // movie -> {price, shop}
    unordered_map<int, set<P>> movieToshopPrice;   // movie -> {shop, price}
    set<tuple<int,int,int>> rented;                // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            available[movie].insert({price, shop});
            movieToshopPrice[movie].insert({shop, price});  // ✅ FIXED
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;

        if (available.count(movie)) {
            for (auto &it : available[movie]) {
                result.push_back(it.second);  // shop
                if (++count >= 5) break;
            }
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        // find price using (shop, price) set
        auto it = movieToshopPrice[movie].lower_bound({shop, INT_MIN});
        
        if (it == movieToshopPrice[movie].end() || it->first != shop) return; // safety
        
        int price = it->second;

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        auto it = movieToshopPrice[movie].lower_bound({shop, INT_MIN});
        
        if (it == movieToshopPrice[movie].end() || it->first != shop) return; // safety
        
        int price = it->second;

        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;

        for (auto &[price, shop, movie] : rented) {
            result.push_back({shop, movie});
            if (++count >= 5) break;
        }
        return result;
    }
};