
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
#define endl "\n"
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


template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

LL to_num(string str)
{
    stringstream ss(str);

    LL x;
    ss>>x;
    return x;
}

const int nmax = 2e5+7;

LL a;
string A,B;

LL dp[20][2][2][180];
int mn_sum;
LL ans_val;

bool go(int pos,int choto,int boro,int sum ,string number)
{
    if(pos==(int)B.size())
    {
//        DBG(number);
       // DBG(sum);
        LL val = to_num(number);

        if(sum<=mn_sum)
        {
            ans_val = val;
            return true;
        }

        return 0;
    }

    LL &ret = dp[pos][choto][boro][sum];

    if(ret!=-1)
        return ret;

    ret = 0;

    int lo = 0, hi = 9;

    if(!choto) hi = B[pos] - '0';
    if(!boro) lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
    {
        ret = go(pos+1, choto | (j<hi), boro | (j>lo), j +sum , number + char(j+'0'));
        if(ret)
            return true;
    }

    return false;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        cin>>a>>mn_sum;

        LL b = 1e18;

        B = to_str(b);
        A = to_str(a);

        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }

        memset(dp,-1,sizeof dp);
        LL ans = go(0,0,0,0,"");

        LL ans__ = ans_val - a;
        cout<<ans__<<endl;
        DBG(ans__);
    }


    return 0;
}

/**

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
    for(T i:v)
    {
        os<<i<<" " ;
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
