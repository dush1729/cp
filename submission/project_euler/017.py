import inflect
p=inflect.engine()

ans=0
for i in range(1,1001):
    ans+=len(p.number_to_words(i).replace('-','').replace(' ',''))
print(ans)