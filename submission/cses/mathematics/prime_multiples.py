n, k = map(int, raw_input().split())
a = map(int, raw_input().split())

ans = 0
for mask in range(1 << k):
	p, odd = 1, 0
	for i in range(k):
		if mask & (1 << i):
			p *= a[i]
			odd ^= 1

	if odd:
		ans -= n / p
	else:
		ans += n / p

print n - ans