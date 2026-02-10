class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<vector<pair<int,int>>>adj(n);

        for(int i = 0;i < flights.size();i++)
        {
          int u =  flights[i][0];
          int v = flights[i][1];
          int wt = flights[i][2];

          adj[u].push_back({v,wt});
        }

        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        dist[src] = 0;
        q.push({0,{src,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int wt = it.second;

                if(cost + wt < dist[adjnode] && stops <= k)
                {
                    dist[adjnode] = cost + wt;
                    q.push({stops + 1, {adjnode,dist[adjnode]}});
                }
            }
        }

        if(dist[dst] == 1e9)
        {
            return -1;
        }

        return dist[dst];
    }
};