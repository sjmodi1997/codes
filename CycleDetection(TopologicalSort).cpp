#define MAX 100001
#define F first
#define S second
#define pb push_back

vector<int> adj[MAX];

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        for(int i=0;i<MAX;i++)
           adj[i].clear();
        int  m = edges.size();
        int inDegree[n];
        memset(inDegree,0,sizeof(inDegree));
        for(int i=0;i<m;i++)
        {
            adj[edges[i][1]].pb(edges[i][0]);
            inDegree[edges[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            cnt++;
            for(int i=0;i<adj[tp].size();i++)
            {
                int v = adj[tp][i];
                inDegree[v]--;
                if(inDegree[v]==0)
                    q.push(v);
            }
        }
        if(cnt==n)
            return true; //NO cycle
        else
            return false;
    }
};
