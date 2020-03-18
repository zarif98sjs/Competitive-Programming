/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL bigMod(LL x,LL n,LL mo) /// x^n % mo
{
    x %= mo;

    LL res = 1;

    while(n>0)
    {
        if(n&1) res = ((res%mo)*(x%mo)) % mo;

        x = ((x%mo)*(x%mo)) %mo;
        n >>= 1;
    }

    return res;

}

int main()
{
	//optimizeIO();

	int tc;
    cin>>tc;

    while(tc--)
    {
        LL x,n;
        cin>>x>>n;

        cout<<bigMod(x,n,10)<<endl;
    }

	return 0;
}
