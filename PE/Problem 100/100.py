from mpmath import *

#TOLERANCE = 0.000000000000001

mp.dps = 15
for b in range(113000000):
    descriminant = 8*b*b - 8*b + 1
    if sqrt(descriminant) % 1 == 0:
        r = (1 - 2*b + sqrt(descriminant))/2
        if b + r != 0 and b + r - 1 != 0 and abs(b/(b + r)*(b - 1)/(b + r - 1) - 0.5) == 0:#<= TOLERANCE:
            k = int((-1 + (1 + 8*(b*b - b))**0.5)/2)
            print("b:", b, " r:", int(r), " T_s:", b*b - b, " k:", k) 

