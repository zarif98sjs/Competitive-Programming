
/*

Note :

If two segments i and j both contains point x, with i < j, then the optimal answer for point x is segment j.
    Because by the problem constraint, segment j is a complete subset of segment i, and segment j has higher start point, so it's shorter.
    So for a point x, its answer the largest index i such that segment[i] contains point x.
    Using this observation, and the fact that queries are given in ascending order, we can solve the problem like follows:
    -. We will keep a stack of "candidate" segments, that is, segments that can possibly contain query[i]. In other words, segments with start point <= query[i]
    -. When we are processing query[i]:
        -. Keep reading segments until we encounter segment with start point > query[i]. Then the candidate segment ends here, because every next segment has an even greater starting point.
        -. When we read a candidate segment, two possibilities:
            -. The segment has endpoint >= query[i]. Then by above observation, answer for query[i] is this segment.
               Push this segment to stack, because it can be candidate segment for next queries.
            -. The segment has endpoint < query[i]. Discard this segment. It cannot possibly become candidate for other queries.
               Why? Because this segment doesn't contain query[i], and every next query is even greater than query[i], so this segment cannot possibly contain any of the next query.
        -. If we can't read any segment that contains the current query, then we check the stack for candidate segment.
           Keep popping the stack until we encounter the first segment that contains the current query. The first valid segment you encounter is the answer for this query.
           Why? Because the stack is always sorted in increasing index, and by above observation, the highest possible index is the answer.
        -. If we still can't find any valid segment, then answer is -1.

    -. Every segment is pushed at most once, popped at most once. Complexity is O(n+m)



Data Structure : Stack (used vector here)

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

const int nmax = 1e5+7;

vector<PII>ara(nmax);

int main()
{
    optimizeIO();

    int n,x,y;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        ara[i]=MP(x,y);
    }

    vector< pair<PII,int> > v; // (segment,idx)

    int cur = 1;

    int m;
    cin>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>x;

        int ans = -1;

        while(cur<=n && ara[cur].F<=x)
        {
            if(ara[cur].S>=x)
            {
                ans = cur;
                v.push_back(MP(MP(ara[cur].F,ara[cur].S),cur));
            }
            cur++;
        }

        if(ans==-1)
        {
            while(!v.empty() && v.back().F.S < x) v.pop_back();
            if(!v.empty()) ans = v.back().S;
        }

        cout<<ans<<endl;
    }

    return 0;
}














