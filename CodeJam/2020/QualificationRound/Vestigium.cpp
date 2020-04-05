#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int t=1;t<=tc;t++)
    {
        int n;
        cin >> n;
        int a[n][n];
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> a[i][j];
                if(i==j)
                    sum += a[i][j];
            }
        }
        int r = 0;
        int c = 0;
        int i=0;
        int j=0;
        unordered_map<int,bool> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[a[i][j]])
                {
                    r++;
                    break;
                }
                mp[a[i][j]] = true;
            }
            mp.clear();
        }  
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(mp[a[i][j]])
                {
                    c++;
                    break;
                }
                mp[a[i][j]] = true;
            }
            mp.clear();
        }
        printf("Case #%d: %d %d %d\n",t,sum,r,c);
    }
    
}
