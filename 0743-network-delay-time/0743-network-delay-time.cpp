class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n);

        // build graph (convert to 0-based index)
        for (auto &e : times) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            int w = e[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, 1e9);
        dist[k - 1] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k - 1});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &neigh : adj[node]) {
                int next = neigh.first;
                int wt   = neigh.second;

                if (dist[next] > d + wt) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
