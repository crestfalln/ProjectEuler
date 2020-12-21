for a in range(1, 10):
    for b in range(1, 10):
        if a == b:
            continue
        else:
            k = 9*a*b/(10*a-b)
            if int(k) - k == 0 and int(k) < 10:
              print(str(a) + str(int(k)) + ", " + str(int(k)) + str(b))