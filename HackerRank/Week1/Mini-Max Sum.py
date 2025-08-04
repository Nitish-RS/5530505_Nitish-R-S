#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    arr.sort()
    minsum=0
    maxsum=0
    for i in range(len(arr)-1):
        minsum=arr[i]+minsum
        maxsum=maxsum+arr[i+1]
    print(minsum,end=" ")
    print(maxsum)
            
    # Write your code here

if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
