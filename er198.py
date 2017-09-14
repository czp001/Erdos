def countPots2Until(n):
	nbPots = {1:n>>1}
	lftMask = ~3
	rgtMask = 1
	digit = 2
	while True:
		lft = (n & lftMask) >> 1
		rgt = n & rgtMask
		nbDigs = lft
		if n & digit:
			nbDigs |= rgt
		if nbDigs == 0:
			return nbPots
		nbPots[digit] = nbDigs
		rgtMask |= digit
		digit <<= 1
		lftMask = lftMask ^ digit
def sumXorSquare(n):
	"""Returns sum(i^j for i, j <= n)"""
	n += 1
	nbPots = countPots2Until(n)
	return 2 * sum(pot * freq * (n - freq) for pot, freq in nbPots.items())
print sumXorSquare(1073742824)%1000000007
