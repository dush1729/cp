N=80
dp=[[0 for x in range(N)] for y in range(N)]

arr=[]
for i in range(N):
	arr.append(map(int,raw_input().split(',')))

dp[0][0]=arr[0][0]
for i in range(1,N):
	dp[0][i]=arr[0][i]+dp[0][i-1]
	dp[i][0]=arr[i][0]+dp[i-1][0]

for i in range(1,N):
	for j in range(1,N):
		dp[i][j]=arr[i][j]+min(dp[i-1][j],dp[i][j-1])
print dp[N-1][N-1]