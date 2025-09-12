#########################################
# UTM FCIM Tehnici de Programare
# LABORATOR nr. 2
# 11.09.2025
# AI-252, anul I
#
# Features: type hints, f-print, for loops, returning lists
#########################################

from typing import List

def count_vocale_consoane(mystr: str) -> List[int]:
    litere = [0, 0] # [Vocale, consoane]
    for c in mystr.lower():
        if c in "aeiou": # 'y' drept vocala ar putea fi rezonabil in unele situatii
            litere[0] += 1
        elif c in "bcdfghjklmnpqrstvwxyz":
            litere[1] += 1
            
    return litere


def main(): # The main function which runs at program start-up
    mystr_ : str = input("Fraza: ")
    res : List[int] = count_vocale_consoane(mystr_)
    print(f"Vocale: {res[0]}\nConsoane: {res[1]}")


if __name__ == "__main__": # Avoid the program running if it is imported in another file
    main()