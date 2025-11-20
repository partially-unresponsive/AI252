from izzyutils.batch1.meowwers import constrained_sum_sample_pos
from cryptography.fernet import Fernet, MultiFernet

# import numpy as np
# import math 
import datetime 
# import os 
import cryptography as crypt 
# import string 

# NOTE: Taken directly from test_attendance.py
def hex_token(n, total):
  """Turns the constrained_sum_sample_pos numbers into hex."""
  return [hex(i) for i in constrained_sum_sample_pos(n, total)]


def hex_to_dec(n):
  return int(n, 16)


def hex_to_dec_list(lst):
  return [int(i, 16) for i in lst]


def main():
  sample = hex_token(3, 6969420)
  print(f"{sample} = {sum(hex_to_dec_list(sample))}")
  # print(sum(constrained_sum_sample_pos(4, 6969420)));
  print(hex_to_dec('0x43'))
  key1 = Fernet(Fernet.generate_key())
  key2 = Fernet(Fernet.generate_key())
  f = MultiFernet([key1, key2])
  token = f.encrypt(b"Meowwers nya~")
  print(f"Token: {token}\nDecrypted: {f.decrypt(token)}")
  # The following 4 lines invalidate the f.decrypt(token) function call, raising an InvalidToken error. Interesting!
  key3 = Fernet(Fernet.generate_key())
  f2 = MultiFernet([key3, key1, key2])
  rotated = f2.rotate(token)
  token = f2.encrypt(b"Meowwers nya~")
  # print(f"Token: {token}\nDecrypted: {f.decrypt(token)}")
  print(f"Token (rotated): {rotated}\nDecrypted: {f2.decrypt(rotated)}")

  print(f"Time: {datetime.datetime.now().strftime("%A, %B %d [%H:%M:%S]")}") # Ex. 3

  
  


if __name__ == "__main__":
  import doctest
  main()
  doctest.testmod()
