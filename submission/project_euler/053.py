N=101

c=[[0 for n in range(N)] for r in range(N)]
ans=0
for n in range(N):
	for r in range(0,n+1):
		if r==0 or r==n:
			c[n][r]=1
		else:
			c[n][r]=c[n-1][r-1]+c[n-1][r]
		if c[n][r]>1000000:
			ans+=1
print ans