class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i = 0;i < edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int>q;
        vector<int>ans;
        
        for(int i = 0;i < indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto edge : adj[temp])
            {
                indegree[edge]--;
                if(indegree[edge] == 0)
                {
                    q.push(edge);
                }
            }
        }
        return ans.size() == numCourses;
    }
};