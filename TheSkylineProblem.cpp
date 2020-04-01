#define pb push_back
#define F first
#define S second

struct building
{
    int x;
    int h;
    bool start;
};

bool mycmp(building b1,building b2)
{
    if(b1.x!=b2.x)
        return b1.x < b2.x;
    if(b1.start==b2.start)
    {
        if(b1.start)
        {
            return b1.h > b2.h;
        }
        else
        {
            return b1.h < b2.h;
        }
    }
    else
    {
        return b1.start > b2.start;
    }
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {    
        vector<building> v;
        vector<vector<int>> ans;
        int len = buildings.size();
        if(len==0)
        {
            return ans;
        }
        for(int i=0;i<len;i++)
        {
            building b1;
            b1.x = buildings[i][0];
            b1.h = buildings[i][2];
            b1.start = true;
            v.pb(b1);
            
            building b2;
            b2.x = buildings[i][1];
            b2.h = buildings[i][2];
            b2.start = false;
            v.pb(b2);
        }
        int n = v.size();
        sort(v.begin(),v.end(),mycmp);      
    
        int prevMax = 0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            //cout << v[i].x << " " << v[i].h << " " << v[i].start << endl;
            if(v[i].start)
            {
                mp[v[i].h]++;
            }
            else
            {
                mp[v[i].h]--;
                if(mp[v[i].h]==0)
                {
                    mp.erase(v[i].h);
                }
            }
            if(mp.empty())
            {
                ans.pb({v[i].x,0});
                prevMax = 0;
                continue;
            }
            auto it = mp.rbegin();
            //cout << it->F << endl;
            if(it->F!=prevMax)
            {
                ans.pb({v[i].x,it->F});
                prevMax = it->F;
            }
        }
        return ans;
    }
};
