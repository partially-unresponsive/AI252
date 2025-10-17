"""
izzy's (self) Base64 decoder
Algorithm taken from https://base64.guru/learn/base64-algorithm/decode
"""

import os
import yaml
from collections import namedtuple # Only needed to secure the following constants as immutable

INPUTFILE = "config.yaml"

Constants = namedtuple('Constants', ['POSSIBLE_ENCODINGS', 'BASE64ALPHABET'])
constants = Constants(POSSIBLE_ENCODINGS = {"BASE64":"implemented", 
                     "ROT13" :"WIP",
                     "CAESAR":"WIP"}, 
                     BASE64ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=")

def dec_to_binary(n: int) -> str:
    return '{0:08b}'.format(n)


def B64decode(encoded_string: str) -> str:
    """Izzyfix: Decode a BASE64 encoded string back to its normal string representation.
    
    >>> B64decode("aXp6eWZpeA==")
    'izzyfix'

    >>> B64decode("ZGVlem51dHo")
    'deeznutz'

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
    if type(encoded_string) != type("meow"):
        raise ValueError("B64decode expects a string type as input")
    for c in encoded_string:
        if c not in constants.BASE64ALPHABET: # Alternatively, you can use if re.search(r"^[A-Za-z0-9+/]+={0,2}$", encoded_string): ...
            raise ValueError("B64decode input string has characters alien to BASE64")
    if encoded_string.strip()=="":
        return ""

    res = ""
    binaries = [] # Stores the binary representation of each "res" value with the first 2 leading 0s removed
    for c in encoded_string:
        if c == "=": # Only used for padding, not encoding
            continue
        elif c not in constants.BASE64ALPHABET:
            continue
        else:
            # print(f"{c}: {constants.BASE64ALPHABET.index(c)}")
            indx = constants.BASE64ALPHABET.index(c)
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
        

def main():
    if os.path.exists(INPUTFILE): # Ex. 1
        with open(INPUTFILE, 'r') as config_file:
            print("NOTE: Reading config file: {INPUTFILE}")
            contents_config = yaml.safe_load(config_file)
            print(contents_config)
            print(f"Filesize: {os.path.getsize(INPUTFILE)}") # Ex. 2
            if "encoding_pattern" in contents_config: # Ex. 3
                print("NOTE: Encoding pattern found. Continuing.")
                encoded_string: str = contents_config.get("encoded_string")
                print(f'Encoded string is: {encoded_string}')
                encoding_pattern: str = contents_config.get("encoding_pattern")
                match (encoding_pattern):
                    case "BASE64":
                        print("NOTE: BASE64 encoding detected. Continuing.")
                        res: str = B64decode(encoded_string)
                    case "ROT13":
                        raise Error("TODO: ROT13 encoding not implemented yet.")
                    case "CAESAR":
                        raise Error("TODO: ROT13 encoding not implemented yet.")
                    case (_): # Default "match anything" case statement
                        return 1
                
                print(f"RESULT: Decoded {encoding_pattern} string is {res}")
    else:
        print("WARNING: {INPUTFILE} does not seem to exist. Injecting default config contents. Rerun the program.")
        with open(INPUTFILE, "w") as ss:
            default_config_contents = """
            encoded_string: "ZGVlem51dHo"
            encoding_pattern: "Base64"
            """
            ss.write(default_config_contents)


# print(open(INPUTFILE).read())
if __name__ == "__main__":
    import doctest
    main()
    doctest.testmod()