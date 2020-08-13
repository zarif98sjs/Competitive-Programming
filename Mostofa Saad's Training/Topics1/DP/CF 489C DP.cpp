
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

int digit,sum;

bool dpMAX[105][1005];
bool dpMIN[105][1005];

string solveMAX(int pos,int s,string ans)
{
    if(s>sum) return "-1";
    if(pos==digit)
    {
        if(s==sum) return ans;
        return "-1";
    }

    bool &ret = dpMAX[pos][s];

    if(ret) return "-1";
    ret = true;

    for(int i=9;i>=0;i--)
    {
        if(pos==0 && i==0 && digit>1) continue; /** First digit can't be 0 except only 0 **/

        char num = i + '0';
        string res = solveMAX(pos+1,s+i,ans+num);

        if(res != "-1") return res;
    }

    return "-1";
}

string solveMIN(int pos,int s,string ans)
{
    if(s>sum) return "-1";
    if(pos==digit)
    {
        if(s==sum) return ans;
        return "-1";
    }

    bool &ret = dpMIN[pos][s];

    if(ret) return "-1";
    ret = true;

    for(int i=0;i<=9;i++)
    {
        if(pos==0 && i==0 && digit>1) continue; /** First digit can't be 0 except only 0 **/

        char num = i + '0';
        string res = solveMIN(pos+1,s+i,ans+num);

        if(res != "-1") return res;
    }

    return "-1";
}

int main()
{
    optimizeIO();

    cin>>digit>>sum;

    string MX = solveMAX(0,0,"");
    string MN = solveMIN(0,0,"");

    cout<<MN<<" "<<MX<<endl;

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


