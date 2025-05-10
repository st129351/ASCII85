import subprocess as sp
import base64 as b64

# the test for endoding data
def TestDecode(inp):
    ascii85_enc = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstu";
    # start new process with Popen
    actions = sp.Popen( 
        ["./ascii85", "-d"],
        stdin = sp.PIPE, # creating PIPE
        stdout = sp.PIPE, # pipe is a channel
        stderr = sp.PIPE # need pipe for give and take data
    )

    decode, err_decode = actions.communicate(input = inp) # transfer input data to process "actions"
    # communicate returns stdout, stderr

    # if '\n' or excess spaces (not spaces in the string) in output, then delete their
    decode = decode.strip()

    # returncode storage the code of ending process (0 - success)
    
    if err_decode:
        # errors outputs in bytes, then decoding it
        err_msg = err_decode.decode().strip()
        print("Error in decoding: ", err_msg)
        return (False, err_msg) # (errors, data is missing)

    true_decoding = b64.a85decode(inp)
    if true_decoding != decode:
        msg = "Oh, incorrect decoding"
        print(msg)
        return (False, msg)
    
    print("Pass test of decoding")
    return (True, decode)