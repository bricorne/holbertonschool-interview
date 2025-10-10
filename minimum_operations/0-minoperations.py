#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    if n <= 1:
        return 0

    # If n is prime, then the minimum operations will be n
    for d in range(2, int(n**0.5) + 1):
        if n % d == 0:
            return minOperations(d) + minOperations(n//d)

    return n
