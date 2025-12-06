# NOTE: Run this using the following command: `python3 Lab5.py && python3 markdown.py`

from cryptography.fernet import Fernet, MultiFernet

import datetime 
import os 
import cryptography as crypt 
import random
import art

def main():
  with open("lab5.md", "w") as f:
    f.write("# TP Laborator 5\n")
    key1 = Fernet(Fernet.generate_key())
    f.write(f"## Ex. 3\n- Afiseaza data si ora curenta intr-un format simplu folosind modulul datetime.\n \n`{datetime.datetime.now().strftime("%A, %B %d [%H:%M:%S]")}`\n") # Ex. 3

    with open("aur.txt", "w") as f2:
      tmp = art.text2art("aur", font="block", chr_ignore=True) # Ex. 4
      f2.write(tmp)
      f.write("## Ex. 4\n- Creeaza un fisier text nou si scrie un mesaj simplu in el folosind modulul os.\n \n`Successfully written to file aur.txt`\n")

  # NOTE: Begin exercise 8 solution
    key2 = Fernet(Fernet.generate_key())
    fer1 = MultiFernet([key1, key2])
    # token = f.encrypt(b"hummina dummina")
    # print(f"Token: {token}\nDecrypted: {f.decrypt(token)}")
    # The following 4 lines invalidate the f.decrypt(token) function call, raising an InvalidToken error. Interesting!
    key3 = Fernet(Fernet.generate_key())
    fer2 = MultiFernet([key3, key1, key2])
    token = fer2.encrypt(b"bleep bloop")
    rotated = fer2.rotate(token)
  #   # print(f"Token: {token}\nDecrypted: {f.decrypt(token)}")
    f.write(f"## Ex. 9\n- Cripteaza si decripteaza un cuvant simplu folosind modulul cryptography.\n \n`Token (rotated): {rotated}`\n\n`Decriptat: {fer2.decrypt(rotated)}`\n")

  # NOTE: End exercise 8 solution

    f.write(f"## Ex. 17\n- Alege si afizeaza o luna dintr-un an dat folosind modulul random.\n\n`{random.choice(["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"])}`\n")
    f.write(f"## Ex. 18\n- Genereaza si afizeaza un numar prim intre 1 si 50 folosind modulul random.\n\n`{random.choice([2, 3, 5, 7, 11, 13, 17, 21, 23, 27, 29, 31, 37, 41, 43, 47])}`\n")

  # NOTE: END LAB 5 SOLUTION
# TODO: Utilize a different Textual example solution than markdown.py, including a button to hot reload the code (Lab5.py) to regenerate the solutions. 
  

if __name__ == "__main__":
  main()
