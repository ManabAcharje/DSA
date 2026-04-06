
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: 0: North, 1: East, 2: South, 3: West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Store obstacles in a set for O(log N) lookup
        set<pair<int, int>> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        int x = 0, y = 0, direction = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -1) { // Turn right
                direction = (direction + 1) % 4;
            } else if (cmd == -2) { // Turn left
                direction = (direction + 3) % 4; // Equivalent to (dir - 1 + 4) % 4
            } else {
                // Move step by step to check for obstacles
                for (int i = 0; i < cmd; ++i) {
                    int nextX = x + dx[direction];
                    int nextY = y + dy[direction];
                    
                    if (obstacleSet.find({nextX, nextY}) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        // Hit an obstacle, stop moving for this command
                        break;
                    }
                }
            }
        }

        return maxDistSq;
    }
};