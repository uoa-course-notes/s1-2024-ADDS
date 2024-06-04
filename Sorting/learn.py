import random 



def generate_random(N: int) -> list: 
    T = []
    for _ in range(N):
        T.append(random.randint(-N, N))
    return T

# Selection Sort
def find_min_index(T: list, begin: int, end: int) -> int: 
    min = begin;
    for i in range(begin+1, end):
        if (T[i] < T[min]):
            # print("yes")  
            min = i
    return min


def isSorted(T: list, N: int) -> bool:
    for i in range(1, N):
        if (T[i] < T[i-1]): return False
    return True


def SELECTION_SORT(T: list, N: int):
    num_swap, num_comp = 0, 0
    for i in range(N):
        min_index = find_min_index(T, i, N)
        T[i], T[min_index] = T[min_index], T[i]
        num_comp = num_comp + 1
        num_swap = num_swap + 1
    return T, num_swap, num_comp


T = [29, 4, 1, 2, 3, -1, -3,44, 28, -939, 481, 3884, 1009, 4994, -129, -300012, 4884, 4]
N = len(T)
T, num_s, num_c = SELECTION_SORT(T, N)
print(f"Sorted array = {T}")
print(f"""
Size = {N}
Number of compares: {num_c}
Number of swaps: {num_s}
      """)
exp = 15



# # print(find_min_index(T, 0, 4))
# print(T)
# T = SELECTION_SORT(T, N)
# print(T)



# Let's generate 10 random elements 


# if isSorted(T, N):
#     print("Yes, our selection sort procedure works!")
# else: print("Please check your procedure again.")

size = 1000000000
exp = 15
COMPARES = []
SWAPS = []
for i in range(exp):
    random_array = generate_random(size)
    sorted, n_s, n_c = SELECTION_SORT(random_array, size)
    # print(f"#{i+1} -> {random_array} -> {sorted} -> isSorted? {isSorted(sorted, size)}")
    COMPARES.append(n_c)
    SWAPS.append(n_s)
    
print(COMPARES, SWAPS)
    


## Analyzing number of comparisons and swaps 









