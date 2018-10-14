
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair

int LIM = 32;
int isP[1010];
vector<int>primes;
vector<PII>nod;

bool cmp(const PII &a,const PII &b)
{
    if(a.second!=b.second)
        return a.second<b.second;
    else
        return a.first>b.first;
}

void sieve()
{
    for(int i=1; i<=1000; i++)
        isP[i]=true;

    for(int i=2; i<=1000; i++)
    {
        //cout<<i<<endl;

        if(isP[i])
        {
            primes.push_back(i);

            for(int j=i*i; j<=1000; j+=i)
                isP[j]=false;
        }
    }
}


int main()
{

    //freopen("OUTLOJ1109.txt","w",stdout);

    sieve();

    for(int num=1; num<=1000; num++)
    {
        //cout<<num<<endl;

        int div=1;
        int n=num;

        for(int i=0; i<primes.size(); i++)
        {
            int x=primes[i];
            int k=0;

            if(n%x!=0)
                continue;

            while(n%x==0)
            {
                n=n/x;
                k++;
            }

            div=div*(k+1);
        }

        nod.push_back(MP(num,div));
    }

    sort(nod.begin(),nod.end(),cmp);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        int num;
        scanf("%d",&num);

        printf("Case %d: %d\n",i,nod[num-1].first);

    }

    return 0;
}


