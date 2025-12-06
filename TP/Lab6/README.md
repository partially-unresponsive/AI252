# util.py – fișierul cu funcții
Acest fișier conține funcțiile „de calcul”, adică logica principală:
✔️ este_prim(n)
Primește un număr.
Verifică dacă numărul este prim.
Returnează True sau False.
✔️ factorial(n)
Primește un număr.
Calculează factorialul lui (ex: 5! = 1×2×3×4×5).
Returnează rezultatul.
✔️ salveaza_prime(pana_la, nume_fisier)
Găsește toate numerele prime până la un număr dat.
Le salvează într-un fișier text cu numele primit ca parametru.
Acesta este modulul de funcții pe care îl folosiți în programul principal.

# main.py – programul principal
Acest fișier este responsabil cu interacțiunea cu utilizatorul:
Programul trebuie să facă următoarele:
Cere utilizatorului un număr (numărul unic pe care îl primește fiecare student).
Afișează:
dacă numărul este prim (folosind funcția din util.py),
factorialul numărului (tot din util.py).
Cere numele studentului.
Folosește salveaza_prime() pentru a salva într-un fișier:
toate numerele prime până la numărul respectiv,
fișierul se va numi prime_NUME.txt (ex: prime_elena.txt).