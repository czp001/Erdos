#include<cstdio>
#include<cmath>
#include<ctime>

using int64 = long long;
using int128 = __int128;

int64 sd(int64 n)
{
	int128 sum=0,i,sq=floor(sqrt(n));
	for(i=1;i<=sq;i++)
	{
		sum+=n/i;
	}
	return 2*sum-sq*sq;
}

int64 k3(int64 n)
{
	int128 x=pow(10,log10(n)/2);
	while(!(x*x*x<=n&&(x+1)*(x+1)*(x+1)>n))
	{
		x=(2*x+n/(x*x))/3;
	}
	return x;
}

int64 st(int64 n)
{
	int64 i,j,n3=k3(n);	
	int64 s=0,s2;
	for(i=1;i<=n3;i++)
	{
		s2=0;
		for(j=1;j<=n3;j++)
		{
			s2+=n/(i*j);
		}
		s+=sd(n/i)-s2;
	}
	return 3*s+n3*n3*n3;
}

int64 f(int64 n)
{
	int64 ans = 0;
	for(int64 i=1,j;i<=n;i=j+1)
	{
		j=n/(n/i);
		ans+=(st(j)-st(i-1))*(n/i);
	}
	return ans;	
}

int main()
{
	//const int64 base = 1000000000000000000ll;
	int64 n=1000000000000ll;
	clock_t start=clock();
	printf("%lld\n",n);
   	printf("%lld\n",f(n));
	//printf("%lld%018lld\n", int64(f(n) / base), int64(f(n) % base));
	printf("%f\n",(clock()-start)/1000000.);
	return 0;
}
