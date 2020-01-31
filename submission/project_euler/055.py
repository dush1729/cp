def lychrel(x,it):
	if str(x)==str(x)[::-1]:
		return False
	if it>=50:
		return True
	return lychrel(x+int(str(x)[::-1]),it+1)

ans=0
for i in range(1,10001):
	if lychrel(i+int(str(i)[::-1]),1):
		ans+=1
print ans