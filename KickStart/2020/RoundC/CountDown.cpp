#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second


using namespace std;

int main() {
	int tc;
	cin >> tc;
	for(int t=1;t<=tc;t++)
	{
	    ll n,k;
	    cin >> n >> k;
	    ll a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> a[i];
	    }
	    int ans = 0;
	    int i=0;
	    while(i<n)
	    {
	        if(a[i]==k)
	        {
	            int cnt = k;
                while(i<n && a[i]==cnt)
                {
                    i++;
                    cnt--;
                }
                if(cnt==0)
                    ans++;
	        }
	        else
	            i++;
	    }
	    printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
