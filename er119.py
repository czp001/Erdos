from math import floor
from math import log10
def k3(n):
	x = 10**int(log10(n)/2)
	while not (x*x*x<=n and (x+1)*(x+1)*(x+1)>n) :
		x=int((2*x+n//(x*x))//3)
	return x

f=[0]*1000005
def iscube(n):
	return n==k3(n)**3
for n in range(1,1000005):
	if iscube(n):f[n]=1
	else:
		f[n]=min([f[n-i**3]+1 for i in range(1,k3(n)+1)])
print sum(f[:10**6+1])
