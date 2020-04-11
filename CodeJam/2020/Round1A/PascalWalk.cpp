#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second

using namespace std;

bool vis[1001][1001];
vector<pair<int,int>> ans;
int sum;
int n;

int dx[6] = {-1,-1,0,0,1,1};
int dy[6] = {-1,0,-1,1,0,1};
bool ansFound;

bool check(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<=x && !vis[x][y])
        return true;
    return false;
}

void dfs(vector<vector<int>> &v, int x,int y)
{
    if(ansFound)
        return;
    //cout << "Entry: " << x << " " << y << endl;
    sum += v[x][y];
    vis[x][y] = true;
    ans.pb({x,y});
    if(sum==n)
    {
        ansFound = true;
        //cout << "--------------------" << endl;
        for(int i=0;i<ans.size();i++)
        {
            //printf("%d %d\n")
            cout << ans[i].F+1 << " " << ans[i].S+1 << endl;
        }
        //cout << "--------------------" << endl;
        //cout << "Exit: " << x << " " << y << endl;*/
        vis[x][y] = false;
        sum -= v[x][y];
        ans.pop_back();
        return;    
    }
    if(sum>n)
    {
        //cout << "Exit: " << x << " " << y << endl;
        vis[x][y] = false;
        sum -= v[x][y];
        ans.pop_back();
        return;
    }
    for(int i=0;i<6;i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(check(xx,yy))
        {
            dfs(v,xx,yy);
        }
    }
    //cout << "Exit: " << x << " " << y << endl;
    sum -= v[x][y];
    vis[x][y] = false;
    ans.pop_back();
}

int main()
{
    ll tc;
    cin >> tc;
    for(int t=1;t<=tc;t++)
    {
        ans.clear();
        memset(vis,false,sizeof(vis));
        sum = 0;
        ansFound = false;
        cin >> n;
        vector<vector<int>> v(n);
        v[0].push_back(1);
        for (int i = 1; i < n; ++i) 
        {
            v[i].push_back(1);
            for (int j = 1; j < i; ++j)
            {
                v[i].push_back(v[i-1][j] + v[i-1][j-1]);
            }
            v[i].push_back(1);
        }
        printf("Case #%d: \n",t);
        dfs(v,0,0);
    }
}
