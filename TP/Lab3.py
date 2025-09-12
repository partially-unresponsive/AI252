#########################################
# UTM FCIM Tehnici de Programare
# LABORATOR nr. 3
# 11.09.2025
# AI-252, anul I
#
# Features: type hints, f-print, custom functions
#########################################

from typing import List, Dict

def numere_pare(mylist : List[int]) -> List[int]:
    pare : List[int] = [val for val in mylist if val % 2 == 0]
    return pare


def suma_pozitive(mylist : List[int]) -> List[int]:
    evens : List[int] = numere_pare(mylist)
    if len(evens) == 0:
        print("[INFO] Lista nu contine numere pare.")
        return evens
    evens_sum : int = sum(evens)
    res = [[evens], evens_sum, evens_sum/len(evens)] # [[Lista numerelor pare], [Suma lor], [Media lor]] 
    return res


def lungimi_cuvinte(mylist: List[str]) -> Dict:
    word_lengths = dict([(w, len(w)) for w in mylist]) # Creating a dictionary with list comprehension
    return word_lengths


def elimina_duplicateA(mylist: List) -> List:
    return list(set(mylist)) # Sets inherently remove all duplicates


def elimina_duplicateC(mylist: List) -> Dict:
    res = dict([(w, mylist.count(w)) for w in mylist]) # Creating a dictionary with list comprehension
    return res


def produs_impare(mylist: List) -> List:
    impare: List[int] = [val for val in mylist if val % 2 == 1]
    if len(impare) == 0:
        print("[INFO] Lista nu contine numere impare.")
        return impare
    p = 1
    for i in impare:
        p *= i
    return [p, impare]


def main(): # The main function which runs
    mylist = [3, 6, 1, 8, 7, 13, 18, 10, 7, 7, 7, 3, 6]
    mywords = ['meow', 'cow', 'The Suffragetes Movement of 1972', 'Barack Obama', '', '       ', 'aa', '\n']
    mylist.sort()
    print(f"Lista: {mylist[:]}")
    print(f"Pare: {numere_pare(mylist)}")
    print(f"Suma_pozitive: {suma_pozitive(mylist)}")
    print(f"Produs_impare: {produs_impare(mylist)}")
    print(f"elimina_duplicateA: {elimina_duplicateA(mylist)}")
    print(f"elimina_duplicateC: {elimina_duplicateC(mylist)}")
    print("=================")
    print(f"Cuvinte: {mywords}")
    print(f"lungimi_cuvinte: {lungimi_cuvinte(mywords)}")


if __name__ == "__main__": # Avoid the program running if it is imported in another file
    main()