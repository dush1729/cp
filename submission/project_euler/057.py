num=1
den=1
ans=0
for i in range(1,1001):
	num+=den
	num,den=den,num
	num+=den
	if len(str(num))>len(str(den)):
		ans+=1
print ans