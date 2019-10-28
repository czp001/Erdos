from time import clock
def prime_sieve(N):
  if N < 2:
    return []
 
  size = (N + 1) // 2
  is_prime = [1] * size
  is_prime[0] = 0
  v = int(N ** 0.5) // 2 + 1
  for p in range(1, v):
    if not is_prime[p]:
      continue
    for k in range(2 * p * (p + 1), size, 2 * p + 1):
      is_prime[k] = 0
 
  primes = [2]
  primes.extend([2 * p + 1 for p in range(1, size) if is_prime[p]])
  return primes
 
def rad_sum(N):
  """
  10 ** 15: 352221100499728129324576243738, 8.1s
  """
  def rec(rest, coef, pi):
    ret = rest * (rest + 1) // 2 * coef
    for i in range(pi, len(primes)):
      p = primes[i]
      nrest = rest // (p * p)
      if nrest == 0:
        break
      ncoef = coef * (-p * (p - 1))
      while nrest >= 1:
        ret += rec(nrest, ncoef, i + 1)
        nrest //= p
    return ret
  v = int(N ** 0.5)
  primes = prime_sieve(v) + [v + 1]
  ret = rec(N, 1, 0)
  return ret
 
def rad_reciprocal_sum(N):
  """
  10 ** 15: 539291778733461810, 5.7s
  """
  def rec(rest, coef, pi):
    ret = rest * coef
    for i in range(pi, len(primes)):
      p = primes[i]
      nrest = rest // (p * p)
      if nrest == 0:
        break
      ncoef = coef * (p - 1)
      while nrest >= 1:
        ret += rec(nrest, ncoef, i + 1)
        nrest //= p
        ncoef *= p
    return ret
  v = int(N ** 0.5)
  primes = prime_sieve(v) + [v + 1]
  ret = rec(N, 1, 0)
  return ret

def radk_sum(N,k):
  def rec(rest, coef, pi):
    ret = S(rest,k) * coef
    for i in range(pi, len(primes)):
      p = primes[i]
      nrest = rest // (p * p)
      if nrest == 0:
        break
      ncoef = coef *(-p**k*(p**k-1))
      while nrest >= 1:
        ret += rec(nrest, ncoef, i + 1)
        nrest //= p
    return ret
  v = int(N ** 0.5)
  primes = prime_sieve(v) + [v + 1]
  ret = rec(N, 1, 0)
  return ret


MOD = 10 ** 9 + 7
Nn=60
def S(n,k):
    fac=[1]*(Nn+2)
    for i in range(2,Nn):
        fac[i]=i*fac[i-1]%MOD
    p=[0]*(k+1+2)
    for i in range(1,k+2+1):
        p[i]=(p[i-1]+pow(i,k,MOD))%MOD
    if(n<=k+2):
        return p[n]
    else:
        x=1
        for i in range(1,k+2+1):
            x=x*(n-i)%MOD

        ans=0
        for i in range(1,k+2+1):
            tmp=pow(fac[k+2-i]%MOD*fac[i-1]%MOD,MOD-2,MOD)
            tmp2=pow(n-i,MOD-2,MOD)
            if((k+2-i)%2):
                tmp=-tmp
            ans =(ans + p[i]*x%MOD*tmp%MOD*tmp2)%MOD
        return ans

        
nn=10**11
start = clock()

s=0
for i in range(1, 50 + 1):
  s=s+radk_sum(nn,i)

print(s%MOD)
print(clock()-start,' secs')
