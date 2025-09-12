#########################################
# UTM FCIM Tehnici de Programare
# LABORATOR nr. 1
# 11.09.2025
# Vasilache Dan, AI-252, anul I
#
# Features: TODO
#########################################

# TODO: Make the program work with N integers, not just 2

from typing import List


user_ : str = input("Nume: ")
N : int = 2  # Number of inputs
nums_ : List[int] = []

print(f"Introduceti {N} numere: ")
for i in range(N):
  tmp_ = int(input(f"Numar {i}: "))
  nums_.append(tmp_)


print("===================")
print(f"Bun venit, {user_}!")
print(f"Ati introdus {nums_[0]} si {nums_[1]}.")

operations_ = [["Suma", "+"], ["Diferenta", "-"], ["Produsul", "*"], ["Catul", "/"], ["Catul intreg", "//"], ["Modulus", "%"], ["Putere", "**"]]

for i, op in operations_:
  print(i + ": " + str(eval(f"{nums_[0]} {op} {nums_[1]}")))
