/*

Idea : Within time complexity only thing to do is binary search i.e use the lower_bound
or the upper bound function to find the value of the index .

Concept (Working of lower_bound & upper_bound function) :
lower_bound --> points to the first number equals to the 'num' or greater than the 'num'
upper_bound --> points to the first number greater than the 'num'

Critical Test Cases (Queries) :
6(present) 10(present) --> r-l+1
5(absent) 10(present) --> r-l+1
5(absent) 9(absent) --> r-l
6(present) 9(absent) --> r-l

*/
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define pi       acos(-1)

#define SI(n)    scanf("%d",&n)
#define SLL(n)   scanf("%lld",&n)
#define SULL(n)  scanf("%llu",&n)
#define SC(n)    scanf("%c",&n)
#define SD(n)    scanf("%lf",&n)

#define fr(i,a,b) for(int i=a ,_b=(b) ;i<= _b;i++)

#define LL      long long
#define PUB     push_back
#define POB     pop_back
#define MP      make_pair
#define PII     pair<int,int>
#define PLL     pair<ll,ll>

#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

int ara[100010];

int main()
{
    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int n,q,a,b,ans;
        SI(n),SI(q);

        fill(ara+1,ara+n+1,0);

        fr(j,0,n-1)
            SI(ara[j]);

        printf("Case %d:\n",i);

        fr(k,1,q)
        {
            SI(a),SI(b);
            int left = lower_bound(ara,ara+n,a)-ara;
            int right = lower_bound(ara,ara+n,b)-ara;

            //cout<<"**"<<left<<" "<<right<<endl;

            if(binary_search(ara,ara+n,b)==true)
                ans = right - left + 1;
            else // binary_search(b)==false
                ans = right - left;

            printf("%d\n",ans);

        }

    }

    return 0;
}
