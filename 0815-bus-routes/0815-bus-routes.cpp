class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>map;
        if(source == target)
        {
            return 0;
        }
        for(int route = 0;route < routes.size();route++)
        {
            for(int stops = 0;stops < routes[route].size();stops++)
            {
                map[routes[route][stops]].push_back(route);
            }
        }

        queue<int>q;
        unordered_set<int>vis;
        for(auto root : map[source])
        {
            q.push(root);
            vis.insert(root);
        }

        int train = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int route = q.front();
                q.pop();
                for(auto stop : routes[route])
                {
                    if(stop == target)
                    {
                        return train;
                    }

                    for(auto nextroute : map[stop])
                    {
                        if(!vis.count(nextroute))
                        {
                            vis.insert(nextroute);
                            q.push(nextroute);
                        }
                    }

                }

            }

            train++;
        }
        return -1;

    }

};