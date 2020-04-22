bandits = input()
cords = []
mindif = 0
excont = 0
peepsdying = []
dyingcont = 0
stuck = 0
rounds = 0
deadnum= 0

while len(cords) < int(bandits):
    cords.append(input())
    print(cords)


while stuck == 0:
    for j in range(int(bandits)):
        #print("j ", j)
        gonethrough = False
        for i in range(int(bandits)):
         #   print("i ", i)
            if j != i:
                #print("j is", cords[j])
                #print("i is", cords[i])
                a, b = cords[j].split(" ")
                c, d = cords[i].split(" ")
                curdif = int(a) - int(c) + int(b) - int(d)
                if not gonethrough:
                    mindif = curdif
                    gonethrough = True
                elif mindif < curdif:
                    mindif = curdif
                    deadguy = cords[i]
                    deadnum = i
                elif mindif == curdif:
                    excont += 1
        if excont < 0:
             deadguy = 0
        if excont == 0:
            peepsdying.append(deadnum)
            dyingcont += 1
    if dyingcont == 0:
        stuck = 1
    print(peepsdying)
    for q in peepsdying:
        #print(q)
        cords.remove(cords[q])
        rounds += 1
print(rounds)
if not cords:
    print("+")
else:
    print(cords)






