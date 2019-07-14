
/*

Note :

Naive implementation if Queue is modified in such a way that current minimum/maximum
can be found in O(1).

Data Structure : Modified Queue (using stack)

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

//queue using stack
stack<pair<int, int>> s1, s2;
int maxx;

void _push(int new_element)
{
    maxx = s1.empty() ? new_element : max(new_element, s1.top().second);
    s1.push({new_element, maxx});
}

int find_maxx()
{
    if (s1.empty() || s2.empty())
        maxx = s1.empty() ? s2.top().second : s1.top().second;
    else
        maxx = max(s1.top().second, s2.top().second);

    return maxx;
}

void _pop()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            int element = s1.top().first;
            s1.pop();
            int maxx = s2.empty() ? element : max(element, s2.top().second);
            s2.push({element, maxx});
        }
    }
    int remove_element = s2.top().first;
    s2.pop();
}

int main()
{
    optimizeIO();

    int m,n=0;
    cin>>m;

    while(true)
    {
        cin>>ara[n];
        if(ara[n]==-1)
            break;
        n++;
    }

    for(int i=0; i<m; i++)
    {
        _push(ara[i]);
    }

    cout<<find_maxx()<<endl;

    n-=m;

    for(int i=0; i<n; i++)
    {
        _pop();
        _push(ara[m+i]);
        cout<<find_maxx()<<endl;
    }

    return 0;
}











