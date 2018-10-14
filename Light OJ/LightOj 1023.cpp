
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

void all_perm(string str,int lim)
{
    int cnt=1;

    do
    {
        cout<<str<<endl;
        cnt++;
        if(cnt>lim)
            break;

    }
    while(next_permutation(str.begin(),str.end()));

}

int main()
{
    string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        printf("Case %d:\n",i);
        int n,k;
        scanf("%d %d",&n,&k);
        all_perm(ALP.substr(0,n),k);

    }

    return 0;
}
