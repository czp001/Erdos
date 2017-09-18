#include <iostream>
#include <cstring>
#include<ctime>

using namespace std;
typedef long long LL;

int mod=1e9+7;

struct Matrix
{
	LL num1, num2;
	bool operator == (const Matrix &x) const
	{
		return num1 == x.num1 && num2 == x.num2;
	}
	Matrix operator * (const Matrix &x) const
	{
		return (Matrix){((LL)num1 * x.num1 + (LL)num2 * x.num2) % (mod-1),
		((LL)num1 * x.num2 + (LL)num2 * (x.num1 + x.num2)) % (mod-1)};
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
    return (a + b) % (mod-1);
}

inline LL mul(LL a, LL b) {
    return (a%(mod-1)) * (b % (mod-1))%(mod-1);
}

inline LL exp(LL a, LL b) {
    int ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans%mod* a%mod;
        a = a%mod* a%mod;
    }
    return ans;
}

int main()
{
    time_t s;
    s=clock();
    const LL MAXN = 1e8+3;

	bool *flag=new bool[MAXN];
	LL *phi=new LL[MAXN];
	LL *p=new LL[MAXN];
	LL *ans=new LL[MAXN];
	LL *ans2=new LL[MAXN];
	LL cnt = 0;
    cnt = 0;
    for(LL i=0;i<MAXN;i++)flag[i]=1;
    phi[1] = 1;
    for(LL i=2; i<MAXN; i++)
    {
        if(flag[i])
        {
            p[cnt++] = i;
            phi[i] = i-1;
        }
        for(LL j=0; j<cnt; j++)
        {
            if(i*p[j] > MAXN)
                break;
            flag[i*p[j]] = false;
            if(i%p[j] == 0)
            {
                phi[i*p[j]] = p[j] * phi[i];
                break;
            }
            else
                phi[i*p[j]] = (p[j]-1)*phi[i];
        }
    }

	for(LL i=0;i<MAXN;i++)
	{
		ans[i]=0;
		ans2[i]=0;
	}
    for(LL i=1; i<MAXN; i++)
        for(LL j=1; j<MAXN; j++)
            if(i*j < MAXN)
            {
            	ans[i*j] +=phi[j]*i;
                ans2[i*j]=add(ans2[i*j],mul(phi[j],fib(i)));
			}
            else
                break;
    for(LL i=1; i<MAXN; i++)
    {
    	ans[i] +=ans[i-1];
        ans2[i] = add(ans2[i],ans2[i-1]);
	}
    cout<<ans[100000000]%mod<<endl;
	cout<<ans2[100000000]<<endl;
	cout<<exp(ans[100000000]%mod,ans2[100000000])<<endl;
    cout<<(clock()-s)*1.0/CLOCKS_PER_SEC<<endl;
}
