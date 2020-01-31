n=1003
m=2
a=[[0 for x in range(m)]for y in range(n)]
a[0][0]=a[0][1]=a[1][0]=a[1][1]=a[2][0]=a[2][1]=a[3][1]=0
a[3][0]=1
try:
    while True:
        x=raw_input()
        x=int(x)
        if x<2:
            print 0
        elif x==2:
            print 1
        elif a[x+1][0]!=0:
            print a[x+1][0]
        else:
            i=3
            while i<=x+1:
                if a[i][0]!=0:
                    i=i+1
                    continue
                a[i][0]=a[i-1][0]+a[i-1][1]
                a[i][1]=a[i-1][0]+a[i-1][1]
                if i%2==1:
                    a[i][0]=a[i][0]+1
                i=i+1
            print a[x+1][0]
except EOFError:
    pass
