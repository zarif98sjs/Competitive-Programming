
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair

vector<int>myf;
vector<int>adj[10010];

int main()
{
    int n,my_f_id,num,x;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&my_f_id);
        myf.push_back(my_f_id);

        scanf("%d",&num);

        for(int j=1;j<=num;j++)
        {
            scanf("%d",&x);
            adj[my_f_id].push_back(x);
        }
    }

    set<int>s;

    for(int f:myf)
    {
        for(int it:adj[f])
        {
            if(find(myf.begin(),myf.end(),it)!=myf.end())
                continue;
            else
                s.insert(it);
        }
    }

    cout<<s.size()<<endl;


    return 0;
}
