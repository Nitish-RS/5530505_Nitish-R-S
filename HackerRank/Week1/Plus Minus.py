#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    p=0
    n=0
    z=0
    for i in range(len(arr)):
        if arr[i]>0:
            p+=1
        elif arr[i]==0:
            z+=1
        else:
            n+=1
    print("{:.6}".format(p/len(arr)))
    print("{:.6}".format(n/len(arr)))
    print("{:.6}".format(z/len(arr)))
    # Write your code here

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
