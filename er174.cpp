//Not finish
#include <iostream>  
#include <cstring>
#include<ctime>

using namespace std;
typedef long long LL;
int mod=1e9+7;
const LL N=1000000000000000000;
const LL fenzi=538660962;
struct Matrix
{
	LL num1, num2;
	bool operator == (const Matrix &x) const
	{
		return num1 == x.num1 && num2 == x.num2;
	}
	Matrix operator * (const Matrix &x) const
	{
		return (Matrix){((LL)num1 * x.num1 + (LL)num2 * x.num2) % (mod),
		((LL)num1 * x.num2 + (LL)num2 * (x.num1 + x.num2)) % (mod)};
	}
	Matrix pow(int k)
	{
		Matrix ret = (Matrix){1, 0}, tmp = *this;
		while(k)
		{
			if(k & 1)
				ret = ret * tmp;
			tmp = tmp * tmp;
			k >>= 1;
		}
		return ret;
	}
} A = {0, 1};
int fib(int n)
{
    return A.pow(n).num2;
}

inline LL add(int a, int b) {
    return (a + b) % mod;
}

inline LL mul(LL a, LL b) {
    return (a*b)%mod;
}

inline LL sub(LL a,LL b){
	return (a+mod-b)%mod;
}

inline LL pow(LL a, LL b) {
    int ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans%mod* a%mod;
        a = a* a%mod;
    }
    return ans;
}

LL si(LL n){
	LL t=fib(n);
	LL pod=t;
	for(int i=1;i<=199;i++){
		pod=mul(pod,sub(t,i));
	}
	return mul(pod,fenzi);
}

LL S(LL n){
	LL s=0;
	for(int i=13;i<=n;i++){
		s=add(s,si(i));
		if(i%100000000==0)cout<<i<<endl;
	}
	return s;
}
int main()
{
    time_t s;
    s=clock();/*
    const LL MAXN = 1e8+3;

	bool *flag=new bool[MAXN];
	LL *phi=new LL[MAXN];
	LL *p=new LL[MAXN];
	LL *ans=new LL[MAXN];
	LL *ans2=new LL[MAXN];*/
	LL Sr=384773643;
	LL Sl=0;
	LL loops=(N+2-13+1)/(2+2*mod);
	LL re=(N+2-13+1)%(2+2*mod);
	cout<<loops<<endl;
	cout<<re<<endl;
	cout<<S(2000000028)<<endl;
    cout<<(clock()-s)*1.0/CLOCKS_PER_SEC<<endl;
}
