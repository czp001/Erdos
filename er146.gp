f(N)=sum(k=1,sqrtnint(N,3),k^3*floor(N/k^3)*(floor(N/k^3)+1)/2*moebius(k))
f(123456789123456789)%1000000007
