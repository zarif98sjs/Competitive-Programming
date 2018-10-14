
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL powa(LL x, int y)
{
    if(y==0)
        return 1;

    LL ans = x;

    for(int i=2; i<=y; i++)
        ans = ans * x;

    return ans;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        LL x;
        scanf("%lld",&x);

        int itr=100;

        LL lo=0;
        LL hi=500000000;
        LL mid,val;
        bool hoise=false;

        while(itr--)
        {
            val=0;

            mid = (lo+hi)/2;
            for(int i=1; i<=27; i++)
                val += (mid/(powa(5,i)));

            //cout<<"mid & val-x is "<<mid<<" "<<val-x<<endl;

            if(val-x>0)
                hi=mid;
            else if(val-x<0)
                lo=mid;

            //cout<<"lo mid & hi "<<lo<<" "<<mid<<" "<<hi<<endl;

            //cout<<"mid & val & x is "<<mid<<" "<<val<<" "<<x<<endl;

            if(val==x)
            {
                hoise=true;
                break;
            }
        }

        if(hoise==false)
            printf("Case %d: impossible\n",i);
        else
        {
            LL ans=(mid/(LL)5)*((LL)5);
            printf("Case %d: %lld\n",i,ans);
        }

    }

    return 0;
}
