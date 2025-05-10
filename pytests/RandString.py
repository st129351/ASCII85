import random as rnd
import string as st

# incredible randomization
def RandomStr(ln):
    inp = ""
    for i in range(ln):
        if rnd.randint(0, 1):
            inp += st.ascii_letters[rnd.randint(0, 51)]
        else:
            inp += st.digits[rnd.randint(0, 9)]
    # convert to binary-file (bytes sequence)
    return inp.encode('utf-8')

def IncorrectRandomStr(ln):
    inp = ""
    for i in range(ln - 1):
        if rnd.randint(0, 1):
            inp += st.ascii_letters[rnd.randint(0, 51)]
        else:
            inp += st.digits[rnd.randint(0, 9)]
    inp += 'y'
    
    return inp.encode('utf-8')