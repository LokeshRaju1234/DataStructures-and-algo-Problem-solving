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
            pair<int,pair<int,int>> curr = q.front();
            q.pop();

            int stops = curr.first;
            int node = curr.second.first;
            int cost = curr.second.second;

            if(stops > k) continue;

            for(int i = 0;i < adj[node].size();i++)
            {
                int adjnode = adj[node][i].first;
                int wt = adj[node][i].second;

                if(wt + cost < dist[adjnode])
                {
                    dist[adjnode] = wt + cost;
                    q.push({stops + 1,{adjnode,dist[adjnode]}});
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