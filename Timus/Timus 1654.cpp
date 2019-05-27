
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

const int nmax = 150007;

stack<char>stk;

int main()
{
    optimizeIO();

    string s;
    cin>>s;

    int len = s.size();

    for(int i=0;i<len;i++)
    {
        if(stk.empty() || stk.top()!=s[i])
            stk.push(s[i]);
        else // stk.top()==s[i]
            stk.pop();
    }

    string temp;

    while(!stk.empty())
    {
        temp.push_back(stk.top());
        stk.pop();
    }

    reverse(temp.begin(),temp.end());
    cout<<temp<<endl;


    return 0;
}










