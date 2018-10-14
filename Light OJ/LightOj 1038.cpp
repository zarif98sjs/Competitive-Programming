
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<int>dv[100010];

void div_hishab(int lim)
{
    for(int i=2;i<=lim;i++)
    {
        for(int j=1;i*j<=lim;j++)
            dv[i*j].push_back(i);
    }
}

double hishab(int n)
{
    if(n==1)
        return 0.00;

    double val = 0.00;
    int siz = dv[n].size();

    for(int i=0;i<siz;i++)
    {
        val += (1.00/(double)siz)*((double)1.00+hishab(n/dv[n][i]));
    }

    return val;
}

int main()
{
    div_hishab(100000);

    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        int n;
        scanf("%d",&n);

        double ans = hishab(n)+(double)1.00;

        if(n==1)
            printf("Case %d: %0.8lf\n",i,ans-(double)1.00);
        else
            printf("Case %d: %0.8lf\n",i,ans);

    }

    return 0;
}
