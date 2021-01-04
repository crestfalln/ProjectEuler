import math
import sys
def pent(num):
    return num*(3*num - 1)/2          
def checkPent(num):
    n = (math.sqrt(24*num +1) + 1)/6
    if(n == (int)(n)):
        return True
    else:
        return False

i = 1
while True:
    sum = pent(i)
    i+=1
    u = 1
    while (u < i):
        diff = pent(u)
        u+=1
        if(checkPent((sum+diff)/2) and checkPent((sum - diff)/2)):
            print(diff)
            sys.exit()
            