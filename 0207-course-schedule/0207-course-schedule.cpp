
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
       vector<int> indeg(numCourses,0);
       for(auto&  p:prerequisites){
        int a=p[0],b =p[1];
        adj[b].push_back(a);
        indeg[a]++;
       }
       queue<int> q;
       for(int i=0;i<numCourses;i++){
        if(indeg[i]==0){
            q.push(i);
        }
       }
       int cnt=0;
       while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(int j : adj[node]){
            indeg[j]--;
            if(indeg[j]==0){
                q.push(j);
            }
        }
       }
       return cnt == numCourses;
    }
};