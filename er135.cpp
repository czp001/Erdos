#include <iostream>
#include <ctime>
using namespace std;
#define ll long long
#define mod 1000000007
const int N=1000010;
ll s[N]={0},t=0,fac[N]={1},tot=0;
inline ll add(ll a, ll b) {
    return (a + b) % mod;
}
inline ll mul(ll a, ll b) {
    return (ll)a * (ll)b % mod;
}

inline ll exp(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
    }
    return ans;
}
void Pre()
{
    for(int i=1;i<=1000000;i++)
    {
        t=(615949*t+797807)%1048576;
        s[i]=t-524288;
        tot=(tot+s[i])%mod;
        fac[i]=i*fac[i-1]%mod;
    }
}

ll P(int n,int deg)
{
    if(n<=deg)return s[n];
    else
    {
        ll x=1;
        for(int i=1;i<=deg;i++)x=x*(n-i)%mod;
        ll ans=0;
        for(int i=1;i<=deg;i++)
        {
            ll tmp=exp(mul(fac[i-1],fac[deg-i]),mod-2);
            ll tmp2=exp(n-i,mod-2);
            if((deg-i)%2)tmp=-tmp;
            ans=add(ans,mul(mul(mul(s[i],x),tmp),tmp2));
        }
        return ans;
    }
}
int main()
{
    int n=1000000;
	time_t start=clock();
	Pre();
    for(int i=1000001;i<=1000100;i++)
    {
	tot=add(tot,P(i,n));
    }
    cout <<"n: "<<n<<"   "<<add(tot,mod)<< endl;
    cout<<(clock()-start)*1.0/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}
