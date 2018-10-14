
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

stack<string>skf;
stack<string>skb;

void init()
{
    while(!skf.empty())
        skf.pop();
    while(!skb.empty())
        skb.pop();
}

int main()
{

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        init();

        printf("Case %d:\n",i);

        string q,web;
        string cur = "http://www.lightoj.com/";
        skb.push(cur);

        while(1)
        {
            cin>>q;
            if(q=="QUIT")
                break;

            if(q=="VISIT")
            {
                cin>>web;
                cur=web;
                skb.push(cur);
                cout<<cur<<endl;

                while(!skf.empty())
                    skf.pop();
            }
            if(q=="BACK")
            {
                if(skb.size()==1)
                {
                    printf("Ignored\n");
                    //string ww =skb.top();
                    //skf.push(ww);
                    continue;
                }

                string ww =skb.top();
                skb.pop();
                cur = skb.top();

                skf.push(ww);
                //skf.push(cur);
                cout<<cur<<endl;
            }
            if(q=="FORWARD")
            {
                //cout<<" skf size is "<<skf.size()<<endl;

                if(skf.empty())
                {
                    printf("Ignored\n");
                    //string ww2 =skf.top();
                    //skb.push(ww2);
                    continue;
                }

                //cout<<" cur is "<<cur<<endl;

                string ww2 =skf.top();
                skf.pop();
                skb.push(ww2);
                cur = skb.top();
                //cur=ww2;
                //skb.push(ww2);
                //skb.push(cur);
                cout<<cur<<endl;
            }
        }
    }

    return 0;
}
