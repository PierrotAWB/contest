T = int(input())
for i in range(T): 
    N = int(input())
    a = bin(N)
    b = a[2:]
    output = ""
    for j in b: 
        if j == '1':
            output += "dank "
        else: 
            output += "meme "
    print (output)