#define MAX 100001
#define F first
#define S second
#define pb push_back

vector<int> adj[MAX];
bool vis[MAX];
bool recStack[MAX];
bool isCycle;

void dfs(int u)
{
    if(isCycle)
        return;
    vis[u] = true;
    recStack[u] = true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(recStack[v])
            isCycle = true;
        if(!vis[v])
            dfs(v);
    }
    recStack[u] = false;
    return;
}

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        for(int i=0;i<MAX;i++)
           adj[i].clear();
        memset(vis,false,sizeof(vis));
        memset(recStack,false,sizeof(recStack));
        isCycle = false;
        int  m = edges.size();
        for(int i=0;i<m;i++)
        {
            adj[edges[i][1]].pb(edges[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i);
            if(isCycle)
                return  false;
        }
        return !isCycle;
    }
};
