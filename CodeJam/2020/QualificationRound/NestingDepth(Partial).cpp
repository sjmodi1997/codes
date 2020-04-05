#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int t=1;t<=tc;t++)
    {
        string s;
        cin >> s;
        int n = s.length();
        string res = "";
        if(n==1)
        {
            if(s[0]=='1')
            {
                printf("Case #%d: (1)\n",t);
            }
            else
            {
                printf("Case #%d: 0\n",t);
            }
            continue;
        }
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(i==0)
                {
                    res += "(1";
                    if(s[i+1]=='0')
                    {
                        res += ")";
                    }
                }
                //res += "1";
                else if(i==n-1)
                {
                    if(s[i-1]=='0')
                    {
                        res += "(";
                    }
                    res += "1)";
                }
                else 
                {
                    if(s[i-1]=='0')
                    {
                        res += "(";
                    }
                    res += "1";
                    if(s[i+1]=='0')
                    {
                        res += ")";
                    }
                }
            }
            else
            {
                res += "0";
            }
        }
        printf("Case #%d: %s\n",t,res.c_str());
    }
}
