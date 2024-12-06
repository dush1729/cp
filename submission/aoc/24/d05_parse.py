for _ in range(1176):
	s = input().split('|')
	print(s[0], s[1])

for _ in range(185):
	s = input().split(',')
	print(len(s), end = ' ')
	for i in range(len(s)):
		print(s[i] + " ", end = '')
	print()