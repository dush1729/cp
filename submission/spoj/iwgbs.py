n=int(raw_input())
counter=0
zero=one=1
while counter<n-1:
    zero,one=one,one+zero
    counter=counter+1
print zero+one
