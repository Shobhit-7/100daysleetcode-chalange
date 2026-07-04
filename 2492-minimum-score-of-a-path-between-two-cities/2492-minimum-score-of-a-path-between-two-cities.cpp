class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &nbr : adj[node]) {
                int next = nbr.first;
                int dist = nbr.second;

                ans = min(ans, dist);

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        return ans;
    }
};