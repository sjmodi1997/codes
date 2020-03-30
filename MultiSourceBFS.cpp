#define F first
#define S second
#define pb push_back

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix.back().size()));
        int n = matrix.size();
        if(n==0)
        {
            return ans;
        }
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j] = 0;
            }
        }
        
        bool vis[n][m];
        memset(vis,false,sizeof(vis));
        queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    pq.push({0,{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        
        while(!pq.empty())
        {
            pair<int,pair<int,int>> tp = pq.front();
            pq.pop();
            int td = tp.F;
            int ti = tp.S.F;
            int tj = tp.S.S;
            for(int i=0;i<4;i++)
            {
                int x = ti+dx[i];
                int y = tj+dy[i];
                if(x>=0 && x<n && y>=0 && y<m)
                {
                    if(!vis[x][y])
                    {
                        if(matrix[x][y]==1)
                        {
                            ans[x][y] = td+1;
                        }
                        vis[x][y] = true;
                        pq.push({td+1,{x,y}});
                    }
                }
            }
        }
        
        return ans;
    }
};
