class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto it :edges){
            int  u=it[0];
            int v=it[1];
            adj[u].push_back(it[1]);
            adj[v].push_back(it[0]);
        }
        queue<pair<int,int>>pq;
        vector<int>dist(n,1e9);
        dist[source]=0;
        pq.push({0,source});
        while(!pq.empty()){
            int distance=pq.front().first;
            int node=pq.front().second;
            pq.pop();
            if(node==destination){
                return true;
            }
            if(distance>dist[node]) continue;
            for(int v:adj[node]){
                int dit=distance+1;
                if(dit<dist[v]){
                    dist[v]=dit;
                    pq.push({dit,v});
                }
            }
        }
        return false;
        
    }
};