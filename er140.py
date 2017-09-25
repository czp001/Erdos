from timeit import default_timer
from math import log
start = default_timer()

def prime_sieve(n):
    sieve = [True] * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1,n//2) if sieve[i]]

prime=prime_sieve(1000010)
def pi(n,k):
    if k<2:
        if k>0:n=int(n**(1./k))
        r = int(n**0.5)
        assert r*r <= n and (r+1)**2 > n
        V = [n//i for i in range(1,r+1)]
        V += list(range(V[-1]-1,0,-1))
        if k==0:S = {i:i-1 for i in V}
        if k==1:S = {i:i*(i+1)//2-1 for i in V}
        for p in range(2,r+1):
            if S[p] > S[p-1]:  # p is prime
                sp = S[p-1]  # sum of primes smaller than p
                p2 = p*p
                for v in V:
                    if v < p2: break
                    S[v] -= p**k*(S[v//p] - sp)
        return S[n]
    else:
		i,ans=1,0
		while prime[i]**k<=n:
			ans+=prime[i]**k
			if 2*prime[i]**k<=n:
				ans+=2*prime[i]**k
			i+=1
		return ans
        
def f(n):
    ans=n+1+pi(n,1)+2*pi(n//2,1)
    Max=int(log(n)/log(2))
    for i in range(2,Max+1):
        ans+=pi(n,i)
    t=1
    for i in range(1,Max+1):
        t+=pi(int((n)**(1./i)),0)+pi(int((n//2)**(1./i)),0)
    t=t-2*(Max-2+1)+1
    ans=ans-2*t
    return ans
ans=0
for i in range(1,12+1):
	ans+=f(10**i)
print ans%1000000007
print default_timer()-start,'secs'
