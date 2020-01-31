N=100
def inc():
	dp=[0]
	for x in range(1,10):
		dp.append(1)
	ans=sum(dp)
	for i in range(2,N+1):
		for j in range(9,-1,-1):
			for k in range(0,j):
				dp[j]+=dp[k]
		ans+=sum(dp)
	return ans

def dec():
	dp=[0]
	for x in range(1,10):
		dp.append(1)
	ans=sum(dp)
	for i in range(2,N+1):
		for j in range(0,10):
			for k in range(j+1,10):
				dp[j]+=dp[k]
		ans+=sum(dp)
	return ans

#9*N to remove overlapping case like 333,44444,11111
print inc()+dec()-9*N