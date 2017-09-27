#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
#define ll long long
#define mod 1000000007
ll qpow(ll a,ll n,ll p)
{
	a=a%p;
	ll ans=1;
	while(n)
	{
		if(n&1)ans=(ans%p)*(a%p)%p;
		a=(a%p)*(a%p)%p;
		n=n/2;
	}
	return ans;
}

ll g(ll n)
{
	return qpow(qpow(qpow(4,n,mod),n,mod),n,mod);
}

ll f(ll n)
{
	ll ans=0;
	for(long long i=1,j,k;i<=n;i=j+1)
	{
		j=n/(n/i);
		ans=(ans+g(n/i)%mod*(j-i+1))%mod;
	}
	return ans;
}

int main(){
	clock_t start=clock();
	ll ans=0;
	for(int i=1;i<=12345678;i++)ans=(ans+f(i))%mod;
	cout << ans<< endl; 
	cout<<(clock()-start)*1.0/CLOCKS_PER_SEC<<" secs "<<endl;
	return 0;
}
