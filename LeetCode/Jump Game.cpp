
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

const int nmax = 1e5;

class Solution {
public:

    /** BIT / FENWICK TREE **/
    /*** 1 based indexing ***/

    LL BIT[nmax];
    void update(int index,int val,int len)
    {
        while(index<=len)
        {
            BIT[index] = BIT[index]+val;
            index += index&(-index);
        }
    }

    LL query(int index)
    {
        LL sum=0;
        while(index>0)
        {
            sum = sum+BIT[index];
            index -= index&(-index);
        }
        return sum;
    }

    void update(int l,int r,int val,int len)
    {
        update(l,val,len);
        update(r+1,-val,len);
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int>num(n+1);

        for(int i=1;i<=n;i++) num[i] = nums[i-1];

        update(1,1,1,n);

        vector<int>t(n+10);

        for(int i=1;i<=n;i++)
        {
            int l = max(1,i - num[i]);
            int r = min(n,i + num[i]);

            int now = query(i);
            cerr<<now<<endl;

            if(now > 0)
            {
                update(l,r,1,n);
            }
        }

        for(int i=1;i<=n;i++)
            if(query(i)==0)
                return false;

        return true;

    }
};

int main()
{
    optimizeIO();

    int n;


    return 0;
}
