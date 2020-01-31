N=40
MAX=1000000
for i in range(N):
	arr=raw_input().split(',')
	for j in range(N):
		if arr[j]=='-':
			print MAX,
		else:
			print arr[j],
	print ""