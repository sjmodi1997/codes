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
	    ll n,d;
	    cin >> n >> d;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> a[i];
	    }
	    ll ans = d;
	    for(int i=n-1;i>=0;i--)
	    {
	        ll x = ans/a[i];
	        ans = x*a[i];
	    }
	    printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}
