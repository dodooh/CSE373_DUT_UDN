import time

def my_runtime(x):
    sum = 0
    start_time = time.time()
    for i in range(x):
        for j in range(1,i*i):
            if(j%i==0):
                for k in range(j):
                    sum+=1
    print(time.time() - start_time)

# my_runtime(2**3)
# my_runtime(2**4)
# my_runtime(2**5)
my_runtime(2**6)
my_runtime(2**7)
# my_runtime(2**8)
# my_runtime(2**9)

# my_runtime(2**10)
# my_runtime(2**11)
# my_runtime(2**12)
# my_runtime(2**13)
# my_runtime(2**14)
# my_runtime(2**15)
