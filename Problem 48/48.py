import time
t = time.time()

# accumulator = 0
# for i in xrange(1, 1001): 
# 	accumulator += i ** i
# print str(accumulator)[len(str(accumulator)) - 10:len(str(accumulator))]


print str(sum(map(lambda x: x ** x, [i for i in range(1001)])))[-10:]
print time.time() - t
