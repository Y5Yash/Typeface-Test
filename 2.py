dict_phone = {"oo": ["u"], "u":["oo"], "y":["i"], "i":["y"]} #This list can be extended
word = ["Moorthy"]
filelist = [] #get all words in this list
ans = []

def search(y):
	temp = []
	z = word.split(y)
	for x in filelist:
		for u in dict_phone(y):
			if (x.split(u)==z):
				temp.append(x)
	return temp
				

for y in dict_phone:
	z = word.split(y)
	if (z[0]!=word):
		lis = search(y)
		ans+=lis

