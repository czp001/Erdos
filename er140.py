#not finish yet
def pi(n,k):
    if k<5:
        n=int(n**(1./k))
        r = int(n**0.5)
        assert r*r <= n and (r+1)**2 > n
        V = [n//i for i in range(1,r+1)]
        V += list(range(V[-1]-1,0,-1))
        if k==0:S = {i:i-1 for i in V}
        if k==1:S = {i:i*(i+1)//2-1 for i in V}
        if k==2:S = {i:i*(i+1)*(2*i+1)//6-1 for i in V}
        if k==3:S = {i:i*i*(i+1)*(i+1)//4-1 for i in V}
        for p in range(2,r+1):
            if S[p] > S[p-1]:  # p is prime
                sp = S[p-1]  # sum of primes smaller than p
                p2 = p*p
                for v in V:
                    if v < p2: break
                    S[v] -= p**k*(S[v//p] - sp)
        return S[n]
    else:
        pass
    return
