class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int finalmask = (1 << n) - 1;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(1<<n,false));
        for(int i = 0;i < n;i++)
        {
            int mask = 1 << i;
            q.push({i,mask});//node with its mask
            visited[i][mask] = true;
        }
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto[node,mask] = q.front();
                q.pop();

                if(mask == finalmask)
                {
                    return steps;
                }
                for(int next : graph[node])
                {
                    int newmask = mask | (1<<next);
                    if(!visited[next][newmask])
                    {
                        q.push({next,newmask});
                        visited[next][newmask] = true;
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};