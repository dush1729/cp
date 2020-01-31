ans=0
for i in range(1,100):
	for j in range(1,100):
		num=pow(i,j)
		sum=0
		while num!=0:
			sum+=num%10
			num/=10
		ans=max(ans,sum)

print(ans)
