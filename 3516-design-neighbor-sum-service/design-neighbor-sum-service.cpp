class NeighborSum {
public:
    vector<vector<int>> mat;
    int n;
    unordered_map<int, pair<int,int>> pos;

    NeighborSum(vector<vector<int>>& grid) {
        mat = grid;
        n = grid.size();

        // Store positions of each value
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        if (pos.find(value) == pos.end()) return 0;

        auto [i, j] = pos[value];
        int sum = 0;

        // Top
        if (i > 0) sum += mat[i - 1][j];

        // Down
        if (i < n - 1) sum += mat[i + 1][j];

        // Left
        if (j > 0) sum += mat[i][j - 1];

        // Right
        if (j < n - 1) sum += mat[i][j + 1];

        return sum;
    }

    int diagonalSum(int value) {
        if (pos.find(value) == pos.end()) return 0;

        auto [i, j] = pos[value];
        int sum = 0;

        // Top-Left
        if (i > 0 && j > 0) sum += mat[i - 1][j - 1];

        // Top-Right
        if (i > 0 && j < n - 1) sum += mat[i - 1][j + 1];

        // Bottom-Left
        if (i < n - 1 && j > 0) sum += mat[i + 1][j - 1];

        // Bottom-Right
        if (i < n - 1 && j < n - 1) sum += mat[i + 1][j + 1];

        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */