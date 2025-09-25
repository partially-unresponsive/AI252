#########################################
# LABORATOR nr. 2
# 11.09.2025
# Features: type hints, f-print, custom functions
#########################################

import random

def check_parity(N: int) -> str:
    if N % 2:
        return "i"  # Modulus = 1, impar
    else:
        return "p"  # Modulus = 0, par


def parity_to_str(mystr: str) -> str:
    match mystr:
        case "p":
            return "par"
        case "i":
            return "impar"
            

def main():   # The main function which runs
    randnum : int = random.randint(1, 100)
    print("Calculatorul a decis un numar intre [1, 100]. Ghiciti daca este un numar par sau impar.")
    guess_ : str = input("Decizie (Par/Impar, p/i): ").lower()[0]  # Only checks the first letter. "p" -> par, "i" -> impar
    if (guess_ not in "pi"):
        raise ValueError("ERR: Nu s-a luat o decizie.") # Unsure whether to throw this error or to simply `return 1` and end the program
    res : str = check_parity(randnum)
    if (guess_ == res):
        print(f"Corect! Numarul ales {randnum} era {parity_to_str(res)}.")
    else:
        print(f"Gresit! Din pacate, numarul ales {randnum} era {parity_to_str(res)}.")
            
        
if __name__ == "__main__":   # Avoid the program running if it is imported in another file
    main()