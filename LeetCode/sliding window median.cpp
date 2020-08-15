
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

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

class Solution
{
public:

    double med = 0;
    multiset<PII, greater<PII>>s;
    multiset<PII>g;
    vector<int>where; /// 1 - s , 2 - g

    void updateMedian()
    {
        LL gv = (*g.begin()).F , sv = (*s.begin()).F;

        if(g.size()>s.size()) med = gv;
        else if(g.size()<s.size()) med = sv;
        else med = ( gv+sv )/2.0;
    }

    void operation(int val,int idx)
    {
        if(s.size()>g.size())
        {
            if(val*1.0<med)
            {
                g.insert(*s.begin());
                where[(*s.begin()).S] = 2;
                s.erase(s.begin());

                s.insert({val,idx});
                where[idx] = 1;
            }
            else
                g.insert({val,idx}) , where[idx] = 2;
        }
        else if(s.size()<g.size())
        {
            if(val*1.0>med)
            {
                s.insert(*g.begin());
                where[(*g.begin()).S] = 1;
                g.erase(g.begin());

                g.insert({val,idx});
                where[idx] = 2;
            }
            else
                s.insert({val,idx}) , where[idx] = 1;
        }
        else if(s.size()==g.size())
        {
            if(val*1.0<med) s.insert({val,idx}) , where[idx] = 1;
            else g.insert({val,idx}) , where[idx] = 2;
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {

        vector<double>ans;

        int n = nums.size();
        where = vector<int>(n);

        for(int i=0; i<n; i++)
        {
            double val = nums[i]*1.0;

            if(i<k-1)
            {
                operation(nums[i],i);
                updateMedian();
            }
            else
            {
                operation(nums[i],i);
                updateMedian();
                ans.push_back(med);

                int id = i-(k-1);
                int er = nums[id];
                int wh = where[id];

                if(wh==1) s.erase(s.lower_bound({er,id}));
                else g.erase(g.lower_bound({er,id}));
            }

//            DBG(where);
//            DBG(med);
        }

        return ans;
    }
};

int main()
{
    optimizeIO();

    int n,k;
    cin>>n>>k;

    vector<int>v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    Solution sol;

    sol.medianSlidingWindow(v,k);

    return 0;
}

/**
8 3
1 3 -1 -3 5 3 6 7
**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


