/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define MAX 100050

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

int BIT[MAX];
int MOD=1000000007;

void update(int index,int val,int len)
{
    index++;

    while(index<=len)
    {
        BIT[index] = (BIT[index]+val)%MOD;
        index += index&(-index);
    }
}

int query(int index)
{
    index++;
    int sum=0;
    while(index>0)
    {
        sum = (sum+BIT[index])%MOD;
        index -= index&(-index);
    }
    return sum%MOD;
}

vector<PII>ara;

bool cmp(PII &a,PII &b)
{
    if(a.F==b.F)
        return a.S>b.S;
    return a.F<b.F;
}


int main()
{
    //freopen("LightOj1085.txt","w",stdout);
    //freopen("in.txt","w",stdin);

//    freopen("alu.txt","r",stdin);
//    freopen("bhorta.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        memset(BIT,0,sizeof BIT);
        ara.clear();

        int n,x;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            ara.push_back(MP(x,i));
            //cout<<"idx --> "<<i<<endl;
        }

        sort(ara.begin(),ara.end(),cmp);

        int got=0,ans=0;

        for(auto val:ara)
        {
            int v=val.F;
            int idx=val.S;

            if(idx==0)
                got=1;
            else
                got=query(idx-1)+1;
            ans=(ans+got)%MOD;
            update(idx,got,n);

            //cout<<"GOT--> "<<got<<" & idx --> "<<idx<<endl;
            //cout<<"idx --> "<<idx<<endl;
        }

        printf("Case %d: %d\n",q,ans);

    }


   return 0;
}
