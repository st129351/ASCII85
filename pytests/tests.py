from RandString import *
from TestDecode import *
from TestEncode import *

def GeneralTests():
    complete = False
    print("RUN TESTS of ENCODER/DECODER")
    test_str = RandomStr(1000)
    incorrect_str = IncorrectRandomStr(1000)

    # for encoder all data is correct
    # no difference between test_str and incorrect_str
    success1, inc_enc = TestEncode(incorrect_str)
    success2, cor_enc = TestEncode(test_str)
    if success1 and success2:
        print("PASSED ALL ENCODING TEST")

    success, cor_dec = TestDecode(cor_enc)
    if success:
        print("PASSED DECODING TEST WITH CORRECT INPUT DATA")
    
    try:
        success, inc_dec = TestDecode(inc_enc)
        if not success:
            raise ValueError(inc_dec) # inc_dec - masage here
    except Exception as e:
        print("PASSED DECODING TEST WITH INCORRECT INPUT DATA")
        print(f"OUTPUT: {e}")
        print("NOT NULL")
        complete = True
    
    return complete

GeneralTests()
    


