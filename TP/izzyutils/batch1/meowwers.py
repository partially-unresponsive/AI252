def skycake():
  """Dummy text to practice package import."""
  print("SkyCake evolves to stay just beyond the cognitive reach of " +
  "the bulk of men. SKYCAKE!!")

def dec_to_binary(n: int) -> str:
  """Safely converts a decimal (base 10) number to binary (base 2) through f-strings."""
  return '{0:08b}'.format(n)


def B64decode(encoded_string: str) -> str:
  """Izzyfix: Decode a BASE64 encoded string back to its normal string representation.
  
  >>> B64decode("aXp6eWZpeA==")
  'izzyfix'

  >>> B64decode("bW96emFyZWxsYQ==")
  'mozzarella'

  >>> [B64decode(ss) for ss in ["cG9tcG8=", "Z2FjaGk=", "dGhlcmUgb25jZSB3YXMgYSBtYW4gZnJvbSBNYXJz"]]
  ['pompo', 'gachi', 'there once was a man from Mars']

  Empty strings pass by without processing
  >>> B64decode("")
  ''

  No data type allowed besides string. 
  >>> B64decode(36)
  Traceback (most recent call last):
      ...
  ValueError: B64decode expects a string type as input
  """
  from collections import namedtuple # Only needed to secure the following constants as immutable
  Constants = namedtuple('Constants', ['POSSIBLE_ENCODINGS', 'BASE64ALPHABET'])
  CONSTS = Constants(POSSIBLE_ENCODINGS = {"BASE64":"implemented", 
                    "ROT13" :"WIP",
                    "CAESAR":"WIP"}, 
                    BASE64ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=")

  if type(encoded_string) != type("meow"):
      raise ValueError("B64decode expects a string type as input")
  for c in encoded_string:
      if c not in CONSTS.BASE64ALPHABET: # Alternatively, you can use if re.search(r"^[A-Za-z0-9+/]+={0,2}$", encoded_string): ...
          raise ValueError("B64decode input string has characters alien to BASE64")
  if encoded_string.strip()=="":
      return ""

  res = ""
  binaries = [] # Stores the binary representation of each "res" value with the first 2 leading 0s removed
  for c in encoded_string:
      if c == "=": # Only used for padding, not encoding
          continue
      elif c not in CONSTS.BASE64ALPHABET:
          continue
      else:
          # print(f"{c}: {CONSTS.BASE64ALPHABET.index(c)}")
          indx = CONSTS.BASE64ALPHABET.index(c)
          binaries.append(dec_to_binary(indx)[2:])
          # print(dec_to_binary(indx)[2:])

  binaries_combined = "".join(binaries)

  segmented = []
  for i in range(0, len(binaries_combined) + 1, 8):
      if (i+8)>len(binaries_combined)+1:
          break # The size of the next segment is too small (less than 8), and gets discarded
      segmented.append(binaries_combined[i:i+8])

  # print(f"SEGMENTED: {segmented}")
  for bb in segmented:
      res += chr(int(bb, 2))
  
  return res



# Taken from Mark Dickinson's GitHub answer
def constrained_sum_sample_pos(n, total):
  """Return a randomly chosen list of n>=1 positive integers summing to total.
  Each such list is equally likely to occur.

  >>> sum(constrained_sum_sample_pos(4, 420))
  420
  
  >>> sum(constrained_sum_sample_pos(1, 500))
  500
  """
  import random

  dividers = sorted(random.sample(range(1, total), n - 1))
  return [a - b for a, b in zip(dividers + [total], [0] + dividers)]
