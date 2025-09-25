#########################################
# LABORATOR nr. 2
# 11.09.2025
# Features: type hints, f-print, constants, RegEx
#########################################

import re

DEBUG_E = False  # Change to True for debug

def check_palindrome(mystr: str) -> bool:
    mystr = mystr.lower()
    mystr = re.sub(r'\ ', '', mystr)
    str_rev = mystr[::-1]
    if DEBUG_E:
        print(f"[DEBUG] Reversed: {str_rev}") 
    return str_rev == mystr
    
    
def main():   # The main function which runs
    mystr_ : str = input("Fraza: ")
    print(f"Fraza '{mystr_}' {"" if check_palindrome(mystr_) else "nu "}este palindrom.")  # Ternary operator a? b: c


if __name__ == "__main__":   # Avoid the program running if it is imported in another file
    main()