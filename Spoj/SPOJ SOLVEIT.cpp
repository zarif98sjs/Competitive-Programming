
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    set<int>s;

    for(int i=1;i<=q;i++)
    {
        int type,idx;
        scanf("%d %d",&type,&idx);

        if(type==1)
            s.insert(idx);

        else
        {
            auto it=s.lower_bound(idx);

            if(it==s.end())
                puts("-1");
            else
                printf("%d\n",*it);
        }

    }


    return 0;
}

