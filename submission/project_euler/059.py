plaintext=map(int,raw_input().split(','))
english_words = ["the","and","for","not","that","have","with","this","from","they"]

def getText(mask):
	key=[]
	for j in range(3):
		key.append(ord('a')+mask%26)
		mask/=26
	text,j="",0
	for ch in plaintext:
		text+=chr(ch^key[j])
		j=(j+1)%3
	return text

ans,mask_found=0,0
for mask in range(26**3):
	text=getText(mask)
	cnt=0
	for word in english_words:
		cnt+=text.count(word)
	if ans<cnt:
		ans=cnt
		mask_found=mask

print sum(bytearray(getText(mask_found)))