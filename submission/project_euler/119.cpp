a,N=[],100
for i in range(2,N):
	for j in range(2,N):
		num=pow(i,j)
		if num<10:
			continue
		s,t=0,num
		while t>0:
			s+=t%10
			t/=10
		if s==i:
			a.append(num)
a=sorted(a)
print a[29]