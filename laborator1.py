#########################################
# UTM FCIM Tehnici de Programare
# LUCRARE PRACTICA nr. 1
# 04.09.2025
# Vasilache Dan, AI-252, anul I
#
# Features:  type hints, datetime, typing, functions, 
#            fprint, classes, ranges, user input,
#            nested arrays, error handling, type casting
#########################################


import math
from datetime import datetime
from typing import List

# Ex. 1
_name: str = input("Name: ")
print(f"> Salutare, maria ta, {_name}!")


# Ex. 2
note: List[int] = []
n: int = 3  # Number of grades
print(f"Introduceti {n} note:")
for i in range(n):
  nota = int(input(f"Nota {i+1}: "))
  note.append(nota)

media = sum(note) / n
print(f"> Media notelor: {media}")


# Ex. 3
dist_total = float(input("Distanta (km): "))
oil_total = float(input("Benzina (L): "))

print(f"> Eficienta benzinei: {dist_total / oil_total} km/L")


# Ex. 4
_mins = int(input("Num. minute: "))
print(f"{math.floor(_mins / 60)} ore, {_mins % 60} minute")


# Ex. 5
class Rect:
  def __init__(self, length: float, width: float):
    self.length = length
    self.width = width
    self.perimeter = self.length*2 + self.width*2
    self.area = self.length*self.width 


_len = float(input("Dreptunghi (lungime): "))
_wid = float(input("Dreptunghi (latime): "))
rectA = Rect(_len, _wid)
print(f"> Perimetru: {rectA.perimeter}")
print(f"> Area: {rectA.area}")


# Ex. 6
curr_year = datetime.now().year
_user_year = int(input("Anul nasterii: "))
user_age = curr_year - _user_year

if user_age < 0:
  print(f"> [ERR] Inca nu te-ai nascut, asteapta {-user_age} ani")
elif user_age == 0:
  print("> Numai ce te-ai nascut")
else:
  print(f"> Varsta de {user_age} ani")


# Ex. 7
def c_to_f(temp_c: float) -> float:
  if temp_c < -273.15: 
    raise ValueError("ERR: Temperature cannot be below 0K")
  return (32 + (temp_c * 1.8))



def f_to_c(temp_f: float) -> float:
  if temp_f < -459.67:
    raise ValueError("ERR: Temperature cannot be below 0K")
  return (5/9)*(temp_f - 32)


_temp = float(input("Temperatura (C): "))
print(f"{c_to_f(_temp)}F")
