s=0
mod=10000000000
for i in range(1,1001):
    s=(s+pow(i,i,mod))%mod
print s
