from time import clock
def gaussian_prime_count(n):
   """Prepare a lookup table to allow us to call P[x] to find number of gaussian primes <=x
   For any x that can be reached as n//i for integer i (returned in reverse order as V)"""
   r = int(n**0.5)
   ps = prime_sieve(r+1)
   assert r*r <= n and (r+1)**2 > n
   V = [n//i for i in range(1,r+1)]
   V += list(range(V[-1]-1,0,-1))  # V is interesting positions in descending order
   S1 = {i:(i-1)//4 for i in V} # Count of integers up to 2..i  of form 4k+1 after sieving primes up to p
   S2 = {i:max(0,(i+1)//4) for i in V} # Count of integers up to 2..i of form 4k+3 after sieving primes up to p
   for i,p in enumerate(ps[1:]): # Skip 2
         p2 = p*p
         if p%4==1:
            sp1 = S1[p-1]  # count of primes smaller than p
            sp2 = S2[p-1]
            for v in V:
               if v < p2: break
               S1[v] -= S1[v//p] - sp1
               S2[v] -= S2[v//p] - sp2
         else:
            sp1 = S1[p-1]  # count of primes smaller than p
            sp2 = S2[p-1]
            for v in V:
               if v < p2: break
               S1[v] -= S2[v//p] - sp2
               S2[v] -= S1[v//p] - sp1   
   return S1[n],S2[n]

def prime_sieve(n):
    sieve = [True] * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1,n//2) if sieve[i]]
    
def ss(n):
    return gaussian_prime_count(n)
    
s=clock()
a=ss(17179869184)
b=ss(8589934592)
print '4k+1:',a[0]-b[0]
print '4k+3:',a[1]-b[1]
print clock()-s,'secs'
