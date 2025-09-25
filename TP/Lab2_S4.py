#########################################
# LABORATOR nr. 2
# 18.09.2025
# Features: type hints, f-print, list comprehension, sum()
#########################################

mywords_ : str = input("Fraza: ")
litere_mici = sum(1 for char in mywords_ if char.islower())
litere_mari = sum(1 for char in mywords_ if char.isupper())
print("="*25)
print(f"Fraza introdusa are {litere_mici} minuscule si {litere_mari} majuscule")