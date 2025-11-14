from izzyutils.batch1.meowwers import constrained_sum_sample_pos

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


if __name__ == "__main__":
  import doctest
  main()
  doctest.testmod()