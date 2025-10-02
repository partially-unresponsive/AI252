#########################################
# LABORATOR nr. 2
# 18.09.2025
# Features: type hints, f-print, recursion
#########################################

# NOTE:  
# def fibonacci(N: int) -> int: 
"""Most common recursion implementation of the Fibonacci sequence"""
#     if (N <= -2):
#         print("WARN: Probabil ca nu vrei F(-n)") # Was considering using https://docs.python.org/3/library/warnings.html
#     if (N <= 1):
#         return 0
#     elif (N == 2):
#         return 1
#     else:
#         return fibonacci(N - 1) + fibonacci(N - 2)
        
# TODO: Consider implementing a solution using lru_cache from functools
# TODO: Consider using PyPy as the interpreter instead of CPython (https://pypy.org)

fibon_processed = [0, 1]

def fibonacci_DP(n: int) -> int: 
    """Dynamic programming version of the Fibonacci sequence"""
    if n < 0:
        print(f"Incorrect input: {n}")
        return -1
    
    elif n < len(fibon_processed):
        return fibon_processed[n]
    else:
        fibon_processed.append(fibonacci_DP(n - 1) + fibonacci_DP(n - 2))
        return fibon_processed[n]


def fibonacci(n: int) -> int:
    """Most naive approach, using a while loop"""
    a, b = 0, 1
    _next = b
    count = 1
    
    while count <= n:
        print(f"F({count}) = {_next}")
        count += 1
        a, b = b, _next
        _next = a + b


def main():
    N: int = int(input("Introduceti N: "))
    print("="*15)
    fibonacci(N)


if __name__ == "__main__":
    main()