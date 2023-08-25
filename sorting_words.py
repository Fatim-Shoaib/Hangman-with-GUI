#print("Hello World")

f = open("dictionary.txt","r")
g = open("easy.txt","a")
h = open("medium2.txt","a")
j = open("hard1.txt","a")
easy = 0
medium = 0
hard = 0

#print(f.readline())
#print(f.readline())

#f.close()

for i in f:
    x = f.readline()
    if (len(x) == 6):
        g.write(x)
        easy += 1
    if (len(x) > 6 and len(x) < 12):
        h.write(x)
        medium += 1
    elif (len(x) > 12):
        j.write(x)
        hard += 1

f.close()
g.close()
h.close()
j.close()

print("Easy: ", easy)
print("Medium: ", medium)
print("Hard: ", hard)

