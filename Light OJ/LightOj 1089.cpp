
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

vector<int>v1;
vector<int>v2;

void init()
{
    v1.clear();
    v2.clear();
}

int main()
{
    //freopen("LightOj1089.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int j=1; j<=tc; j++)
    {

        init();

        int n,q;
        scanf("%d %d",&n,&q);

        int a,b;

        printf("Case %d:\n",j);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&a,&b);
            v1.push_back(a);
            v2.push_back(b);
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        int pt;

        for(int i=0; i<q; i++)
        {
            scanf("%d",&pt);

            int val1=upper_bound(v1.begin(),v1.end(),pt)-v1.begin();
            int val11=lower_bound(v2.begin(),v2.end(),pt)-v2.begin();
//            int val2=n-(lower_bound(v2.begin(),v2.end(),pt)-v2.begin());
//            int val22=n-(upper_bound(v1.begin(),v1.end(),pt)-v1.begin());

//            cout<<"val1 --> "<<val1<<" val11 --> "<<val11<<endl;
//            cout<<"val2 --> "<<val2<<" val22 --> "<<val22<<endl;

            //int ans=min(val1-val11,val2-val22);

            printf("%d\n",val1-val11);
        }
    }

    return 0;
}
