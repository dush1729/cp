import random

def eval(ex,x):
	ex=ex.replace("x",str(x))
	ex=ex.replace("X",str(1-x))
	if ex[1]=='|':
		return str(int(ex[0])|int(ex[2]))
	elif ex[1]=='&':
		return str(int(ex[0])&int(ex[2]))
	else:
		return str(int(ex[0])^int(ex[2]))

def go(a,x):
	while len(a)!=1:
		s=""
		for i in range(0,len(a)):
			if a[i]=='(' and a[i+4]==')':
				s=a[i:i+5]
				break
		a=a.replace(s,eval(s[1:4],x))
	if a=='0' or a=='1':
		return a
	else:
		if a=='x':
			return str(x)
		else:
			return str(1-x)

t,tc=int(raw_input()),1
while tc<=t:
	a,ans=raw_input(),0
	if go(a,0)!=go(a,1):
		ans=1
	print "Case #"+str(tc)+": "+str(ans)
	tc+=1