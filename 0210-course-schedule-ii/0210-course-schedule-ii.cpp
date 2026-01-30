class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
                vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i = 0;i < edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        vector<int>ans;
        
        for(int i = 0;i < indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(auto edge : adj[temp])
            {
                indegree[edge]--;
                if(indegree[edge] == 0)
                {
                    q.push(edge);
                    ans.push_back(edge);
                }
            }
        }

        reverse(ans.begin(),ans.end());
        if(ans.size() == V)
        {
            return ans;
        }
        else
        {
        return {};;
        }
    }
};