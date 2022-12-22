class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int p1Left = 0, p1Top = 0, p2Left = 0, p2Top = 0;

        // Loop until all elements have been rotated
        while (true) {
            int i = 0;

            // Rotate elements in the current quadrant
            while (p1Left + i < p2Left - i) {
                swap(matrix[p1Top - i][p1Left + i], matrix[p2Top + i][p2Left - i]);
                ++i;
            }

            // Move to the next quadrant
            if (p1Top + 1 < matrix.size()) {
                p1Left = 0;
                ++p1Top;
                ++p2Left;
                p2Top = 0;
            } else if (p1Left + 1 < matrix[0].size()) {
                ++p1Left;
                ++p2Top;
            } else {
                // All elements have been rotated
                break;
            }
        }

        // Reverse the rows of the matrix
        for (int i = 0; i < matrix.size(); ++i) {
            int lP = 0, rP = matrix[i].size() - 1;
            while (lP < rP) {
                swap(matrix[i][lP], matrix[i][rP]);
                ++lP;
                --rP;
            }
        }
    }
};