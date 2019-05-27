
/*

Note :

If the top of the stack is the same as current char , then pop.
Otherwise push into the stack.

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

const int nmax = 25007;
const int nmax2 = 100007;

int ara[nmax];
int hoise[nmax2];

int main()
{
    optimizeIO();

    int m,n=0;
    cin>>m;

    while(true)
    {
        cin>>ara[n];
        if(ara[n]==-1) break;
        n++;
    }

    priority_queue<int>pq;

    for(int i=0;i<m;i++) pq.push(ara[i]);
    cout<<pq.top()<<endl;

    n-=m;

    for(int i=0;i<n;i++)
    {
        pq.push(ara[m+i]);
        hoise[ara[i]]++; // means excluding this one from the range

        while(hoise[pq.top()]) // as long as the excluded one to this point is still at the top
        {
            hoise[pq.top()]--;
            pq.pop();
        }

        cout<<pq.top()<<endl;
    }

    return 0;
}











