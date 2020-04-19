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
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> a[i];
	    }
	    int ans = 0;
	    for(int i=1;i<n-1;i++)
	    {
	        if(a[i]>a[i-1] && a[i]>a[i+1])
	        {
	            ans++;
	        }
	    }
	    printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
