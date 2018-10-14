
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
#define LL long long

int powa(int x,int n)
{
    if(n==0)
        return 1;
    int u=powa(x,n/2);
    u=u*u;
    if(n%2==1)
        u=u*x;
    return u;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; t++)
    {
        string dec;
        string bin;
        cin>>dec>>bin;

        int l1=dec.length();
        int l2=bin.length();

        string temp="";
        vector<int>todec;
        int val=0,j=0;

        for(int i=l2-1; i>=0; i--)
        {
            if(bin[i]!='.')
            {
                if(bin[i]=='1')
                    val+=powa(2,j++);
                else
                    j++;
                //cout<<"bin[i] "<<bin[i]<<endl;
            }
            else
            {
                //cout<<"val "<<val<<endl;
                todec.push_back(val);
                val=0;
                j=0;
            }
        }
        todec.push_back(val);

        vector<int>givendec;

        for(int i=0; i<=l1; i++)
        {
            if(dec[i]!='.')
                temp+=dec[i];
            else
            {
                //cout<<"temp "<<temp<<endl;
                stringstream ss(temp);
                int x;
                ss>>x;
                givendec.push_back(x);
                temp="";
            }
        }

        stringstream ss(temp);
        int x;
        ss>>x;
        givendec.push_back(x);
        temp="";

        int cnt=0;

        for(int i=0; i<4; i++)
        {
            //printf("%d %d\n",todec[i],givendec[3-i]);

            if(todec[i]==givendec[3-i])
                cnt++;
        }

        if(cnt==4)
            printf("Case %d: Yes\n",t);
        else
            printf("Case %d: No\n",t);


    }

    return 0;
}


