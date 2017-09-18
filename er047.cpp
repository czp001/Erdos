#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <ctime>
using namespace std;

typedef long long LL;

const int maxn = 200000;
const int MOD = 2333333;
const int maxp = 131100;

long long pcnt, prime[maxp];
short mu[maxn];
bool vis[maxn];

void preprocess() {
	mu[1] = 1;
	for(int i = 2; i < maxn; i++) {
		if(!vis[i]) {
			mu[i] = -1;
			prime[pcnt++] = i;
		}
		for(int j = 0; j < pcnt && i * prime[j] < maxn; j++) {
			vis[i * prime[j]] = true;
			if(i % prime[j] != 0) mu[i * prime[j]] = -mu[i];
			else {
				mu[i * prime[j]] = 0;
				break;
			}
		}
	}

	for(int i = 2; i < maxn; i++) mu[i] += mu[i-1];
}


int main()
{
	clock_t start=clock();
	preprocess();
	int ans=0;
	for(long long i=2147483648;i<=4294967295;i++)
	{
		int flag=1;
		for(int j=0;j<=12250;j++)
		{
			if((4*i+3)%prime[j]==0){flag=0;break;}
		}
		ans+=flag;
	}	
	printf("%d\n",ans);
	printf("%f\n",(clock()-start)/1000000.);
	return 0;
}
