#########################################
# LABORATOR nr. 2
# 11.09.2025
# Features: type hints, f-print, errors, returning arrays
#########################################

from typing import List

def check_divisors(N : int) -> List[int]:
    if N < 0:
        raise ValueError("ERR: Introduceti o valoare pozitiva.")
    
    divisors : List[int] = []
    for i in range(1, N+1):   # Make sure no division by 0 happens, include N itself
        if (N % i == 0):
            divisors.append(i)
            
    return divisors


def main():   # The main function which runs
    N_ : int = int(input("Numarul: "))
    print(f"Divizorii lui {N_} sunt:")
    for i in check_divisors(N_):
        print(i, end=' ')   # To place the output all on one line

    print() # Newline at the end for prettiness


if __name__ == "__main__":   # Avoid the program running if it is imported in another file
    main()