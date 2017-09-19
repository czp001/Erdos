#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
const int maxn = 10000000;
bool is_prime[maxn];
bool is_prime_small[maxn];
ll prime[maxn];
ll prime_num=0;

//对区间[a,b)内的整数执行筛法，is_prime[i-a]=true  ---  表示i是素数 注意这里下标偏移了a，所以从0开始。
ll segment_sieve(ll a,ll b) {
	prime_num=0;
    for(ll i=0;i*i<b;++i) is_prime_small[i]=true; //对[2,sqrt(b))的初始化全为质数
    for(ll i=0;i<b-a;++i) is_prime[i]=true; //对下标偏移后的[a,b)进行初始化

    for(ll i=2;i*i<b;++i) {
        if(is_prime_small[i]) {
            for(ll j=2*i;j*j<b;j+=i) is_prime_small[j]=false;  //筛选[2,sqrt(b));
            //(a+i-1)/i得到最接近a的i的倍数，最低是i的2倍，然后筛选
            for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;
        }
    }
    for(ll i=0;i<b-a;++i)  //统计个数
        if(is_prime[i]&&(i%4==3)) prime[prime_num++]=i+a;
	return prime_num;
}

int main()
{
	clock_t start=clock();
    ll a,b,ans=0;
    for(ll i=1;i<=858;i++)
    {
        memset(prime,0,sizeof(prime));
        ans+=segment_sieve(8589934592+(i-1)*10000000,8589934592+i*10000000);
    }
	ans+=segment_sieve(17169934592,17179869184);
	printf("%lld\n",ans);
	printf("%f\n",(clock()-start)/1000000.);
    return 0;
}
