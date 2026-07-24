class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int v : nums) {
            auto prev = dp;

            // 0 times -> already copied

            for (int x = 0; x < MAXX; x++) {
                if (prev[0][x]) {
                    dp[1][x ^ v] = true;   // use once
                    dp[2][x] = true;       // use twice
                    dp[3][x ^ v] = true;   // use three times
                }

                if (prev[1][x]) {
                    dp[2][x ^ v] = true;
                    dp[3][x] = true;
                }

                if (prev[2][x]) {
                    dp[3][x ^ v] = true;
                }
            }
        }

        int ans = 0;
        for (bool ok : dp[3])
            if (ok) ans++;

        return ans;
    }
};