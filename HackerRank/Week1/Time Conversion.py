#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    sep=s[:8].split(':')
    h=int(sep[0])
    if s[8]=='A':
        if (h)==12:
            h=0
    elif s[8]=='P':
        if (h)!=12:
            h+=12
            
    ch=str(h).zfill(2)
    return( f"{ch}:{sep[1]}:{sep[2]}")
    # Write your code here

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
