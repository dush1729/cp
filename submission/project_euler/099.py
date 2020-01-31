import math

line=1
mxval=0
for i in range(1000):
	x,y=map(int,raw_input().split(','))
	val=y*math.log(x)
	if mxval<val:
		mxval=val
		line=i+1
print line