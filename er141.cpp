#include<cstdio>
#include<cmath>
#include<map>
#include<ctime>
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N = 21600000;
int prime[N + 1], M[N + 1];
LL pow(int x,int n){
	LL v=1;
	for(;n;n>>=1){
		if(n&1)v=1ll*v*x%P;
		x=1ll*x*x%P;
	}
	return v;
}
int b[1007]={1},fac[1007],fiv[1007];
int s[10000000]={0};
int C(int n,int m)
{
	return fac[n]*1ll*fiv[m]%P*fiv[n-m]%P;
}
void pre(){
	fac[0]=fiv[0]=1;
	for(int i=1;i<=1005;++i){
		fac[i]=1ll*fac[i-1]*i%P;
		fiv[i]=pow(fac[i],P-2);
	}
	for(int i=1;i<=1005;++i){
		for(int j=0;j<i;++j)b[i]=(b[i]+1ll*C(i+1,j)*b[j])%P;
		b[i]=-1ll*b[i]*pow(i+1,P-2)%P;
		if(b[i]<0)b[i]+=P;
	}
	for(int i=1;i<10000000;++i)s[i]=(s[i-1]+pow(i,1000))%P;
}

void preMob()
{
    M[1] = 1;
    for (int i = 2;i <= N;i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            M[i] = -1;
        }
        for (int j = 1;j <= prime[0] && i <= N / prime[j];j++) {
            prime[i*prime[j]] = 1;
            if (i%prime[j] == 0) {
                M[i*prime[j]] = 0;
                break;
            }
            else {
                M[i*prime[j]] = -M[i];
            }
        }
    }
    for (int i = 2;i <= N;i++)M[i]=(M[i-1]+M[i]*pow(i,1000))%P;
}

LL Ss(LL n)
{
    if(n<1000000)return s[n];
    int k=1000;
    LL ans=0;
    n=(n+1)%P;
    for(int i=1,pw=n;i<=k+1;++i,pw=1ll*pw*n%P){
        ans=(ans+1ll*C(k+1,i)*b[k+1-i]%P*pw)%P;
    }
    ans=1ll*ans*pow(k+1,P-2)%P;
    if(ans<0)ans+=P;
	return ans;
}

map<LL, LL>mp;
LL calMob(LL n)
{
    if (n <= N) return M[n];
    if (mp.count(n)) return mp[n];
    LL ans = 0;
	for(LL i = 2, j; i <= n; i = j + 1) {
		j = n / (n / i);
		ans += (Ss(j) - Ss(i - 1))%P * calMob(n / i)%P;
		ans=(P+ans)%P;
	}
	ans = (P+1 - ans)%P;
    return mp[n] = ans;
}

int main()
{
    clock_t start=clock();
    pre();
    preMob();
    printf("%lld\n",calMob(100000000000));
    printf("%f\n",(clock()-start)*1.0/CLOCKS_PER_SEC);
    return 0;
}
