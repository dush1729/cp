import math
x=math.factorial(100)
s=0
while (x>0):
    s+=x%10
    x/=10
print s
