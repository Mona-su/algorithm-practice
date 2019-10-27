
import math
import os
import random
import re
import sys



#
# Complete the 'divide' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER dividend
#  2. INTEGER divisor
#

def findMaxCommonFactor(a, b):
    a, b = (a, b) if a >= b else (b, a)
    if a%b == 0:
        return b
    else:
        return findMaxCommonFactor(b, a%b)

def findFactors(a):
    i = 2
    factors = []
    while (i*i <= a):
        if (a%i == 0):
            factors.append(int(i))
            # factors.append(int(a/i))
            a = int(a/i)
            i -= 1
        i += 1
    factors.append(a)
    factors = list(set(factors))
    return factors

def divide(dividend, divisor):
    # Write your code here
    maxFactor = findMaxCommonFactor(dividend, divisor)
    # return str(maxFactor)
    dividend = dividend/maxFactor
    divisor = divisor/maxFactor
    factors = findFactors(divisor)
    # return str(dividend) + ',' + str(divisor)
    divisible = True
    for i in range(len(factors)):
        if factors[i] != 1 and factors[i] != 2 and factors[i] != 5:
            divisible = False
            break
    if divisible:
        if dividend%divisor == 0:
            return str(dividend//divisor)
        else:
            return str(dividend/divisor)
    result = str(dividend/divisor)
    # return result
    results = result.split('.')
    floating = ''
    i = 0
    findRepeat = False
    while i < len(results[1]) and not findRepeat:
        j = i + 1
        while j <= len(results[1]):
            floating = str(results[1][i:j])
            ending = (i+2*(j-i)) if (j-i < len(results[1])-j) else len(results[1])
            floating_next = str(results[1][j:ending])
            print(str(ending) + '-' + str(j))
            temp = floating[0:len(floating_next)]
            if temp == floating_next and temp != '':
                findRepeat = True
                break
            j += 1
        i += 1
    floating = results[1][0:i-1] + '(' + floating + ')'
    return results[0] + '.' + floating
    

temp = divide(2, 4)
print(temp)
