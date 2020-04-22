inp = input()
prod = 0
total = 0

a, b = inp.split(" ")
#print("a", a)
#print("b", b)

for i in range(int(a), int(b)):
#    print(i)
    power = len(str(i))
    #print("power is ", power)
    for j in map(int, str(i)):
 #       print(j)
        prod += j**power
    if prod == i:
        total += 1
        print(prod)
    prod = 0
if total == 0:
    print("Rien")


