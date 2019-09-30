
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 3e5+7;

int ara[nmax];

int main()
{
    optimizeIO();

    int n,M;
    cin>>n>>M;

    for(int i=1;i<=n;i++)
        cin>>ara[i];

    int maxx = 0,cur = 0, l =1;

    for(int i=1;i<=n;i++)
    {
        cur += ara[i];

        while(cur>M)
        {
            cur -= ara[l];
            l++;

            if(cur<=M)
                maxx = max(maxx,cur);
        }

        if(cur<=M)
                maxx = max(maxx,cur);
    }

    cout<<maxx<<endl;







    return 0;
}

