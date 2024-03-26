import numpy as np
import matplotlib.pyplot as plt 

import random

def gen_array(N: int) -> list[int]:
    A = []
    for _ in range(N):
        A.append(random.randrange(-N, N))
    return A

def LINEAR_SEARCH(T: list[int], key: int) -> int:
    c1,c2,c3 = 0,0,0
    for i in range(len(T)):
        c1 += 4
        if T[i] == key: 
            # print(i)
            c3+=1
        c2+=1   
    # sum = c1+c2+c3    
    return c1+c2+c3

# fig2, ax2 = plt.subplots()


size = 2
key = 0
INPUTS = []

exp: int = 100
SUMS_ARRAY = []


for i in range(exp):
    INPUTS.append(size)
    size += 1
    X = gen_array(size)
    s = SUMS_ARRAY.append(LINEAR_SEARCH(X, key=X[size-1]))
    print(f"Array #{i+1} -> {X} size = {size} --> #ops = {SUMS_ARRAY[i]}")

    
# print(INPUTS, SUMS_ARRAY)        
fig1, ax1 = plt.subplots() # Create a figure containing a single axes
ax1.plot(INPUTS, SUMS_ARRAY) # Plot some data on axes

plt.show()