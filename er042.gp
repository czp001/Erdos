f=prod(i=1,10000,Mod(1/(1-x^i)+O(x^10001),1000000007));
lift(polcoeff(f,10000))
