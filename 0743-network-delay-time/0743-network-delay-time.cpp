class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n);

        for(int i = 0;i < times.size();i++)
        {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>dist(n,1e9);
        dist[k - 1] = 0;
        pq.push({0,k - 1});

        while(!pq.empty())
        {
            auto [d,n] = pq.top();
            pq.pop();

            if(d > dist[n]) continue;
            for(auto neigh : adj[n])
            {
                int node = neigh.first;
                int wt = neigh.second;

                if(dist[node] > d + wt)
                {
                    dist[node] = d + wt;
                    pq.push({dist[node],node});
                }
            }
        }
        
int ans = 0;
        for(int i = 0;i < n;i++)
        {
            if(dist[i] == 1e9)
            {
                return -1;
            }

            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
