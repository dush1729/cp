t=int(raw_input())
counter=0
while counter<t:
    x,n=[int(x) for x in raw_input().split()]
    ans=cards=x
    while cards>=n:
        ans=ans+cards/n
        cards=(cards/n)+(cards%n)
    print ans
    counter=counter+1
