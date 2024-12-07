def ok(a, target):
	for mask in range(0, 1 << (len(a) - 1)):
		curr = int(a[0])
		for i in range(1, len(a)):
			if (mask & (1 << (i - 1))):
				curr *= int(a[i])
			else:
				curr += int(a[i])
			if curr > target:
				break
		if curr == target:
			return True
	return False

ans = 0
for _ in range(850):
	s = input().split(':')
	target = int(s[0])
	a = s[1].split(' ')[1:]
	if ok(a, target):
		ans += target
print(ans)