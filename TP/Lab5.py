# NOTE: TEXTUAL TUI ZONE

"""
Personal attempt at implementing a TUI using Textual.

Sample goal: idk. Finish lab 5 with this?
"""

from textual.app import App, ComposeResult
from textual.containers import Container, Horizontal
from textual.widgets import Button, Footer, Header, Static

QUESTION = "Do you want to learn about Textual CSS?"


class ExampleApp(App):
    CSS_PATH = "Lab5.tcss"

    def compose(self) -> ComposeResult:
        yield Header(name="Laborator 5 (Py)")
        yield Footer()
        yield Container(
            Static(QUESTION, classes="question"),
            Horizontal(
                Button("Yes", variant="success"),
                Button("No", variant="error"),
                classes="buttons",
            ),
            id="dialog",
        )


# if __name__ == "__main__":
#     app = ExampleApp()
#     app.run()




# NOTE: END TEXTUAL TUI ZONE


# NOTE: START LAB 5 SOLUTION

from izzyutils.batch1.meowwers import constrained_sum_sample_pos
from cryptography.fernet import Fernet, MultiFernet

import datetime 
import os 
import cryptography as crypt 
import random
import art

# NOTE: Taken directly from test_attendance.py
def hex_token(n, total):
  """Turns the constrained_sum_sample_pos numbers into hex."""
  return [hex(i) for i in constrained_sum_sample_pos(n, total)]


def hex_to_dec(n):
  return int(n, 16)


def hex_to_dec_list(lst):
  return [int(i, 16) for i in lst]


def main():
#   sample = hex_token(3, 6969420)
#   print(f"{sample} = {sum(hex_to_dec_list(sample))}")
#   # print(sum(constrained_sum_sample_pos(4, 6969420)));
#   print(hex_to_dec('0x43'))
  key1 = Fernet(Fernet.generate_key())
  print(f"Ex. 3: {datetime.datetime.now().strftime("%A, %B %d [%H:%M:%S]")}") # Ex. 3
# NOTE: Begin exercise 8 solution
  key2 = Fernet(Fernet.generate_key())
  f = MultiFernet([key1, key2])
  token = f.encrypt(b"hummina dummina")
  print(f"Token: {token}\nDecrypted: {f.decrypt(token)}")
  # The following 4 lines invalidate the f.decrypt(token) function call, raising an InvalidToken error. Interesting!
  key3 = Fernet(Fernet.generate_key())
  f2 = MultiFernet([key3, key1, key2])
  token = f2.encrypt(b"bleep bloop")
  rotated = f2.rotate(token)
#   # print(f"Token: {token}\nDecrypted: {f.decrypt(token)}")
  print(f"Token (rotated): {rotated}\nDecrypted: {f2.decrypt(rotated)}")

# NOTE: End exercise 8 solution

  with open("aur.txt", "w") as f:
    tmp = art.text2art("aur", font="block", chr_ignore=True) # Ex. 4
    f.write(tmp)


  print(f"Ex. 17: {random.choice(["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"])}")
  print(f"Ex. 18: {random.randint(1, 50)}")

  
# NOTE: END LAB 5 SOLUTION
  


if __name__ == "__main__":
  # import doctest
  main()
#   doctest.testmod()
