
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
#define PLL pair<long long,long long>
#define MP make_pair
#define LL long long

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    //freopen("LOJ1396.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        string num;
        cin>>num;

        int flag=1;

        int len=num.size();

        if(len%2==1)
        {
            string half_first=num.substr(0,len/2);
            string half_second=num.substr(len/2+1,len);

            string half_first_rev=half_first;
            reverse(half_first_rev.begin(),half_first_rev.end());

            string ans;

            for(int j=0; j<len/2; j++)
            {
                if(half_first_rev[j]==half_second[j])
                    continue;
                if(half_first_rev[j]>half_second[j])
                {
                    ans=half_first+num[len/2]+half_first_rev;
                    flag=0;
                    break;
                }
                else
                {
                    //char ch=num[len/2]+1;
                    half_first=half_first+num[len/2];
                    string sum_string=findSum("1",half_first);
                    string new_half_first=sum_string.substr(0,len/2);
                    string new_half_first_rev=new_half_first;
                    reverse(new_half_first_rev.begin(),new_half_first_rev.end());
                    ans=new_half_first+sum_string[len/2]+new_half_first_rev;
                    flag=0;
                    break;
                }
            }

            if(flag==1)
            {
                half_first=half_first+num[len/2];
                string sum_string=findSum("1",half_first);
                string new_half_first=sum_string.substr(0,len/2);
                string new_half_first_rev=new_half_first;
                reverse(new_half_first_rev.begin(),new_half_first_rev.end());
                ans=new_half_first+sum_string[len/2]+new_half_first_rev;

                flag=0;
            }

            int cnt=0;

            for(int k=0; k<len; k++)
            {
                if(num[k]=='9')
                    cnt++;
            }

            if(cnt==len)
            {
                string new_ans;
                new_ans+="1";
                new_ans.append(len-1,'0');
                new_ans+="1";
                cout<<"Case "<<i<<": "<<new_ans<<endl;
            }

            else
                cout<<"Case "<<i<<": "<<ans<<endl;


            /*string half=num.substr(0,len/2);
            num[len/2]=num[len/2]+1;
            string half2=half;
            reverse(half2.begin(),half2.end());
            string temp=half+num[len/2]+half2;
            cout<<temp<<endl;*/
        }

        if(len%2==0)
        {
            string half_first=num.substr(0,len/2);
            string half_second=num.substr(len/2,len);

            string half_first_rev=half_first;
            reverse(half_first_rev.begin(),half_first_rev.end());

            //cout<<half_first_rev<<"++"<<half_second<<endl;

            string ans;

            for(int j=0; j<len/2; j++)
            {
                if(half_first_rev[j]==half_second[j])
                    continue;
                if(half_first_rev[j]>half_second[j])
                {
                    ans=half_first+half_first_rev;
                    flag=0;
                    break;
                }
                else
                {
                    string sum_string=findSum("1",half_first);
                    string new_half_first=sum_string;
                    string new_half_first_rev=new_half_first;
                    reverse(new_half_first_rev.begin(),new_half_first_rev.end());
                    ans=new_half_first+new_half_first_rev;

                    flag=0;
                    break;
                }
            }

            if(flag==1)
            {
                string sum_string=findSum("1",half_first);
                string new_half_first=sum_string;
                string new_half_first_rev=new_half_first;
                reverse(new_half_first_rev.begin(),new_half_first_rev.end());
                ans=new_half_first+new_half_first_rev;

                flag=0;
            }

            int cnt=0;

            for(int k=0; k<len; k++)
            {
                if(num[k]=='9')
                    cnt++;
            }



            if(cnt==len)
            {
                string new_ans;
                new_ans+="1";
                new_ans.append(len-1,'0');
                new_ans+="1";
                cout<<"Case "<<i<<": "<<new_ans<<endl;
            }

            else
                cout<<"Case "<<i<<": "<<ans<<endl;

            /*string half=num.substr(0,len/2);
            num[len/2]=num[len/2]+1;
            string half2=half;
            reverse(half2.begin(),half2.end());
            string temp=half+num[len/2]+half2;
            cout<<temp<<endl;*/
        }

    }





    return 0;
}
