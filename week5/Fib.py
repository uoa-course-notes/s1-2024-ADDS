import matplotlib.pyplot as plt 
import numpy as np 




def printArray(A: list[int]):
    for _ in range(len(A)):
        print(A[_], sep=", ")
    print()

def generate_fib(n: int, seed: int) -> list[int]:
    # x = seed
    T = [seed]
    y = 1
    for _ in range(n-1): 
        T.append(y)
        seed = y
        y = T[_] + seed
    return T
    
    
def fib(n: int, s = 0) -> list[int]:
    if n < 0: return []
    return generate_fib(n, seed=s)



# Generate 10 fibonacci numbers
N: int = 100
y_axis = fib(N, 0)
# printArray(y_axis)


x_axis = np.arange(0, N, 1)


fig, ax = plt.subplots()
ax.plot(x_axis, y_axis)
plt.show()

