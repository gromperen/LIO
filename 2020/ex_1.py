a = int(input())
counter = 0

for i in range(-9, 9):
    if -1 < a + 3 * i < 10:
        counter += 1
#		print(a, a+i, a+i+i, a+i+i+i)
#		print("c is", counter)
print(counter)
