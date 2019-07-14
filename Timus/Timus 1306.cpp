
/*

Note :

Can't use array to sort because of 1 MB memory limit.
So using priority queue with unsigned int.

Data Structure : Priority Queue

*/


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

const int nmax = 100007;

int main()
{
    //optimizeIO();

    int n;
    unsigned int a;
    priority_queue<unsigned int> Q;

    scanf("%d",&n);

    bool odd = (n % 2 == 1);

    for(int i = n/2; i >= 0; --i)
    {
        scanf("%u",&a);
        Q.push(a);
    }

    n -= n/2 + 1;

    for(int i = 0; i < n; ++i)
    {
        scanf("%u",&a);
        Q.push(a);
        //printf("%u\n",Q.top());
        Q.pop();
    }

    if(odd)
        printf("%u\n",Q.top());
    else
    {
        a = Q.top();
        Q.pop();

        printf("%.1f\n",(a + Q.top()) / 2.0);
    }

    return 0;
}












