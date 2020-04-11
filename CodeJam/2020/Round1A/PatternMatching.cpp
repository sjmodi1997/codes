#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second


const int N = 101;
string s[N];
string a[N][2];
int n;

void solve() 
{
	cin >> n;
	string pref = "", suf = "";
	for (int i = 0; i < n; i++) 
	{
		cin >> s[i];
		int p = 0;
		while(s[i][p] != '*') 
		    p++;
		a[i][0] = s[i].substr(0, p);
		if((int)a[i][0].length() > (int)pref.length()) pref = a[i][0];
		    p = (int)s[i].length();
		while(s[i][p - 1] != '*') 
		    p--;
		a[i][1] = s[i].substr(p, (int)s[i].length() - p);
		if ((int)a[i][1].length() > (int)suf.length()) 
		    suf = a[i][1];
	}
	for (int i = 0; i < n; i++) 
	{
		if (pref.substr(0, (int)a[i][0].length()) != a[i][0]) 
		{
			cout << "*\n";
			return;
		}
		if (suf.substr((int)suf.length() - (int)a[i][1].length(), (int)a[i][1].length()) != a[i][1]) {
			cout << "*\n";
			return;
		}
	}
	//cout << pref << " " << suf << endl;
	string ans = pref;
	for (int i = 0; i < n; i++)
		for (char c : s[i])
			if (c != '*')
				ans.push_back(c);
	ans += suf;
	cout << ans << "\n";
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) 
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
