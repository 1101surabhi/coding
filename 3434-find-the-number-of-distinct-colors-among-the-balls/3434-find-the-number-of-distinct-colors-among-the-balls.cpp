class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;  // Maps ball to its color
        unordered_map<int, int> colorCount; // Maps color to its count
        unordered_set<int> distinctColors;
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0];
            int newColor = query[1];

            // If the ball was previously colored
            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];
                colorCount[oldColor]--;
                if (colorCount[oldColor] == 0) {
                    distinctColors.erase(oldColor);
                }
            }

            // Update the color of the ball
            ballColor[ball] = newColor;
            colorCount[newColor]++;
            distinctColors.insert(newColor);

            // Record the number of distinct colors
            result.push_back(distinctColors.size());
        }

        return result;
    }
};