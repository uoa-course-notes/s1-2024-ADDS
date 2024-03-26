import numpy as np
import matplotlib.pyplot as plt 

import random

def LINEARITY(IN: list[int], OUT:list[int]):
    # Using the defintion of linear mapping
    # F(aX) = aF(X) for all X in IN and a, an arbitary real number
    # F(X + Y) = F(X) + F(Y) for every elements X and Y in IN

    # Using the definition of slope
    # 
    pass


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

exp: int = 1000
SUMS_ARRAY = []


for i in range(exp):
    INPUTS.append(size)
    size += 1
    X = gen_array(size)
    s = SUMS_ARRAY.append(LINEAR_SEARCH(X, key=X[size-1]))
    # print(f"Array #{i+1} -> {X} size = {size} --> #ops = {SUMS_ARRAY[i]}")

    
# print(INPUTS, SUMS_ARRAY)        
x = np.linspace(0,2,100)

fig1, ax1 = plt.subplots() # Create a figure containing a single axes
# ax1.plot(INPUTS, SUMS_ARRAY) # Plot some data on axes
ax1.scatter(INPUTS, SUMS_ARRAY, facecolor='C0', edgecolor='k')
# ax1.plot(INPUTS,x,label="linear")
# ax1.plot(INPUTS,x**2,label="quadratic")
# ax1.plot(INPUTS,x**3,label="cubic")
ax1.set_title("Linear Search Analysis")
# ax1.legend() # Add a legend
ax1.set_xlabel(f"Input Size ({INPUTS[0]} ----> {INPUTS[len(INPUTS) - 1]})")
ax1.set_ylabel("Output Sums of elementary operations")
plt.show()