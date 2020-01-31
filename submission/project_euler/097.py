ans=0
for i in range(1,10):
	for j in range(1,25):
		num=str(pow(i,j))
		if len(num)==j:
			ans+=1
		elif len(num)>j:
			break

print ans