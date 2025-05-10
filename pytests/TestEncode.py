import subprocess as sp
import base64 as b64

# the test for endoding data
def TestEncode(inp):
    # start new process with Popen
    actions = sp.Popen( 
        ["./ascii85"],
        stdin = sp.PIPE, # creating PIPE
        stdout = sp.PIPE, # pipe is a channel
        stderr = sp.PIPE # need pipe for give and take data
    )

    encode, err_encode = actions.communicate(input = inp) # transfer input data to process "actions"
    # if '\n' or excess spaces (not spaces in the string) in output, then delete their
    encode = encode.strip()

    if err_encode:
        # errors outputs in bytes, then decoding it
        print("Error in encoding: ", err_encode.decode().strip())
        return (False, err_encode) # (errors, data is missing)

    true_encoding = b64.a85encode(inp)
    if true_encoding != encode:
        print("Oh, incorrect encoding")
        return (False, "Oh, incorrect encoding")
    
    print("Pass test of encoding")
    return (True, encode)