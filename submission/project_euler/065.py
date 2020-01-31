N,arr,i=100,[2,1,2],2
while len(arr)<N:
	arr.append(1)
	arr.append(1)
	arr.append(i*2)
	i+=1
while len(arr)>N:
	arr.pop()

ans=0
num=1
den=arr.pop()
for i in range(N-1):
	num+=den*arr.pop()
	num,den=den,num
num,den=den,num
print sum(map(int,str(num)))