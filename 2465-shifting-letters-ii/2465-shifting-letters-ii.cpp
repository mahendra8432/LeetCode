class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0); // Difference array for storing shifts

        // Apply shifts using the difference array
        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if (direction == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }

        // Calculate the net shifts for each character
        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift += diff[i];
            s[i] = 'a' + ((s[i] - 'a' + shift) % 26 + 26) % 26;
        }

        return s;
    }
};
