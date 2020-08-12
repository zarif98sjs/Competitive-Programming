
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

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}


const int nmax = 2e5+7;

int main()
{
    optimizeIO();

    int digit,sum;
    cin>>digit>>sum;

    if(digit==1 && sum==0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }

    int rem = sum;

    string mx = "";

    for(int i=0;i<digit;i++)
    {
        if(rem>9) mx += "9" , rem -= 9;
        else mx += to_str(rem) , rem = 0;
    }

    if(mx[0]=='0' || rem!=0 ) cout<<-1 <<" "<<-1<<endl;
    else
    {
        string mn = mx;
        reverse(ALL(mn));

        if(mn[0]=='0')
        {
            mn[0] = '1';

            for(int i=1; i<(int)mn.size(); i++)
            {
                if(mn[i]!='0')
                {
                    mn[i] -= 1;
                    break;
                }
            }
        }

        DBG(mx);
        DBG(mn);

        cout<<mn<<" "<<mx<<endl;
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


