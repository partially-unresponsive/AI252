#########################################
# LABORATOR nr. 2
# 11.09.2025
# Features: type hints, f-print, recursive programs
#########################################

def factorial(N : int) -> int:
    if N < 0:
        raise ValueError("ERR: Introduceti un numar pozitiv.")
    if N == 0:
        return 1
    else:
        return factorial(N-1)*N
    
    
def main():   # The main function which runs
    N_ : int = int(input("Numarul: "))
    print(f"{N_}! = {factorial(N_)}")


if __name__ == "__main__":   # Avoid the program running if it is imported in another file
    main()