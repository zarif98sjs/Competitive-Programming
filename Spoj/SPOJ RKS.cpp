/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair

int ara[1010];

map<int,int>MAP;
map<int,int>pos;

vector<PII>v;

bool cmp(const PII &a,const PII &b)
{
    if(a.first!=b.first)
        return a.first>b.first;
    else
        return pos[a.second]<pos[b.second];

}


int main()
{
    int n,c;
    scanf("%d %d",&n,&c);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ara[i]);

        //if(MAP.find(ara[i])==MAP.end())
          //  MAP[ara[i]]=1;
        //else
            MAP[ara[i]]++;

    }

    for(int i=n;i>=1;i--)
        pos[ara[i]]=i;

    map<int,int>::iterator it;

    for(it=MAP.begin();it!=MAP.end();it++)
    {
        v.push_back(MP(it->second,it->first));
    }

    sort(v.begin(),v.end(),cmp);

    vector<int>ans;

    for(int i=0;i<v.size();i++)
    {
        int koybar=v[i].first;
        while(koybar>0)
        {
            ans.push_back(v[i].second);
            koybar--;
        }
    }
        //cout<<v[i].second<<" "<<v[i].first<<endl;

    for(int xx:ans)
        cout<<xx<<" ";



    return 0;
}
