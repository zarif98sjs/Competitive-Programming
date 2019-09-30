
/**

FIRST OF ALL WE CHECK MAXIMUM NUMBER OF PERMUTATIONS POSSIBLE FROM THE
GIVEN STRING ... IF IT IS < N THAN ANS IS IMPOSSIBLE.

NOW WE HAVE TO FIX  CHARACTER AT EACH POSITION STARTING FROM MSB POSITION ,

FOR FIXING THE CHARACTER AT ANY POSITION INITIALLY WE TRY TO FIX SMALLEST CHARACTER
AT THAT POSITION IF BY PLACING THAT CHARACTER NUMBER OF PERMUTATION FORMED >=  REMAINING
REQUIRED PERMUTATION THAN FIX THIS CHARTER AT THAT POSITION ,
AND DECREASE THE FREQUENCY OF THIS CHARACTER SINCE THIS CHARACTER  IS USED AT THIS
POSITION AND MOVE TO NEXT POSITION , ELSE IF NO OF PERMUTATION FORMED BY PLACING THIS
CHARACTER IS LESS THAN THE REQUIRED REMAINING PERMUTATION THAN DECREASE REMAINING
PERMUTATION BY THE NUMBER OF PERMUTATION FORMED BY PLACING THIS CHARACTER AT THAT
POSITION ( SINCE  THIS COUNT TIMES NUMBER OF PERMUTATIONS COMES IN BETWEEN CURRENT
TO FINAL PERMUTATION ) AND TRY TO FIND NEXT CHARACTER FOR THIS POSITION..

**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e6+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

LL nCr[30][30];
int cnt[30];
int len;


LL count_perm(int n)
{
    LL ret = 1;

    for (int i = 0; i < 26; i++)
    {
        ret *= nCr[n][cnt[i]];
        n -= cnt[i];

    }
    return ret;
}

LL solve(int pos,int rem)
{
    if(pos>=len)
        return 0;

    int i;

    for(i=0;i<26;i++)
    {
        if(cnt[i])
        {
            cnt[i]--;

            LL use = count_perm(len-pos-1);

            //cout<<i<<"  -->  "<<use<<endl;

            if(use>=rem)
                break;

            cnt[i]++;
            rem -= use;
        }
    }

    cout<<char(i+'a');

    solve(pos+1,rem);
}

int main()
{
    for(int i=0; i<=20; i++)
    {
        nCr[i][0]=1;
        nCr[i][i]=1;
        for(int j=1; j<=i; j++)
        {
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
        }
    }

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {

        memset(cnt,0,sizeof cnt);

        string s;
        int nth;
        cin>>s>>nth;

        len = s.size();

        for(int i=0; i<len; i++)
            cnt[s[i]-'a']++;

        cout<<"Case "<<q<<": ";

        if(count_perm(len)<nth)
        {
            cout<<"Impossible";
        }
        else
            solve(0,nth);

        cout<<endl;

    }

    return 0;
}
