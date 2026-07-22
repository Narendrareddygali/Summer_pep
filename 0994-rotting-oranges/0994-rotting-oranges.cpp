class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis= grid;queue<pair<int,int>>q;
        int cntf=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==2){
                    q.push({i,j});
                }if(vis[i][j]==1){cntf++;}
            }
        }
        if(cntf==0){return 0;}
        if(q.empty()){return -1;}
        int minutes=-1;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto[x,y]=q.front();q.pop();
                for(auto[dx,dy]:dir){
                    int i=x+dx;
                    int j=y+dy;
                    if(i>=0 && i<m &&
                     j>=0 && j<n && 
                     vis[i][j]==1){
                        vis[i][j]=2;cntf--;q.push({i,j});
                    }
                }

            }minutes++;
        }
        if(cntf==0){return minutes;}
        return -1;
        
    }
};