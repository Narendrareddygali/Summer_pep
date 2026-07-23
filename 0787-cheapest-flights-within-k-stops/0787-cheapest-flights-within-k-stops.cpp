class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> backup = dist;

            for (auto &flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                if (backup[u] != INF) {
                    dist[v] = min(dist[v], backup[u] + cost);
                }
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};