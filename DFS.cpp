bool vis[1001][1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool isSafe(int i,int j,int n,int m)
{
    if((i>=0) && (i<n) && (j>=0) && (j<m) && (!vis[i][j]))
        return true;
    return false;
}

void dfs(vector<vector<char>> &a,int i,int j,int n,int m)
{
    //cout << i << " " << j << endl;
    vis[i][j] = true;
    for(int k=0;k<4;k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if(isSafe(x,y,n,m))
        {
            if(a[x][y]=='1')
            {
                dfs(a,x,y,n,m);
            }
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& a) {
        int n = a.size();
        if(n==0)
        {
            return 0;
        }
        int m = a[0].size();
        memset(vis,false,sizeof(vis));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && a[i][j]=='1')
                {
                    ans++;
                    dfs(a,i,j,n,m);
                }
            }
        }
        return ans;
    }
};
