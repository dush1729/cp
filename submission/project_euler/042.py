def f(a):
	s=0
	for i in a:
		s+=ord(i)-ord('A')+1
	return s

tri=[]
for i in range(1,20):
	tri.append(i*(i+1)/2)

a=raw_input()
a=a.replace('\"','').replace(',',' ').split()

ans=0
for i in a:
	if f(i) in tri:
		ans+=1

print ans
