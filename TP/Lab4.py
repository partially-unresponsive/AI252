import os

# Ex. 1
if os.path.exists("testme.md"):
    print("File exists")
else:
    with open("testme.md", "w") as ss:
        ss.write("Meowwers")



with open("testme.md", "r") as ss:
    print(ss.read())