#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second

using namespace std;

const int maxn=100000+11;
int a[maxn];
int s[maxn];
unordered_map<int,int> h;
int main() {
    int cases;
    scanf("%d",&cases);
    for (int zz=1;zz<=cases;zz++){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d",a+i);
            s[i]=s[i-1]+a[i];
        }
        h.clear();
        h[0]++;
        int mn=0;
        ll ans=0;
        for (int i=1;i<=n;i++){
            int x=s[i];
            for (int j=0;x-j*j>=mn;j++){
                auto it=h.find(x-j*j);
                if (it!=h.end()) {
                    ans += it->second;
                }
            }
            h[s[i]]++;
            if (s[i]<mn){
                mn=s[i];
            }
        }
        printf("Case #%d: %lld\n",zz,ans);
    }
    return 0;
}
