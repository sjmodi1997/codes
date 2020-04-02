bool check(int m1[],int m2[])
{
    for(int i=0;i<26;i++)
        if(m1[i]!=m2[i])
            return false;
    return true;
}
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        if(n==0 || m==0 || m>n)
            return ans;
        int mpp[26] = {0};
        int mps[26] = {0};
        for(int i=0;i<m;i++)
        {
            mpp[p[i]-'a']++;
            mps[s[i]-'a']++;
        }
        if(check(mpp,mps))
        {
            ans.push_back(0);
        }
        for(int i=m;i<n;i++)
        {
            mps[s[i]-'a']++;
            mps[s[i-m]-'a']--;
            if(check(mpp,mps))
                ans.push_back(i-m+1);
        }
        return ans;
    }
};
