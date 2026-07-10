class Solution {
public:
    vector<int>pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // pos[original index] = position in sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // Component IDs
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        // next[i] = farthest reachable position in one jump
        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && arr[r + 1].first - arr[i].first <= maxDiff)
                r++;
            nxt[i] = r;
        }

        const int LOG = 18; // 2^17 > 1e5

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][ up[k - 1][i] ];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            if (a > b)
                swap(a, b);

            int cur = a;
            int jumps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    jumps += (1 << k);
                }
            }

            ans.push_back(jumps + 1);
        }

        return ans;
    }
};