def ok(a):
	for i in range(1, len(a)):
		if a[i] < a[i - 1] or a[i] - a[i - 1] < 1 or a[i] - a[i - 1] > 3:
			return False
	return True

ans = 0
for _ in range(1000):
	a = list(map(int, input().split()))
	if ok(a) or ok(list(reversed(a))):
		ans += 1
print(ans)