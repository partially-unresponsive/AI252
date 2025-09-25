#########################################
# LABORATOR nr. 2
# 18.09.2025
# Features: type hints, f-print, recursion
#########################################

def fibonacci(N: int) -> int: # Recursive version
    if (N <= -2):
        print("WARN: Probabil ca nu vrei F(-n)") # Was considering using https://docs.python.org/3/library/warnings.html
    if (N <= 1):
        return 0
    elif (N == 2):
        return 1
    else:
        return fibonacci(N - 1) + fibonacci(N - 2)
        

def fibonacciB(N: int) -> int: # For loop version
    # TODO: Use either dynamic programming or caching for solving the problem. Otherwise it's no fun :P
    return 0

for i in range(-5, 20):
    print(fibonacci(i))