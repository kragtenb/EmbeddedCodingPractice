#!/usr/bin/python3
'''
You are given a list of integers. Write a function in C++ or Python to 
find the first integer in the list that does not repeat. If all integers 
repeat, return None or -1 (depending on your preference).

Input: [4, 5, 1, 2, 0, 4, 5, 1, 2]
Output: 0

Input: [4, 4, 5, 5, 1, 1, 2, 2]
Output: None
'''
import pytest
from typing import List

def firstNonRepeatingInt(nums: List[int]) -> int:
    freq = {}
    # O(n)
    for n in nums:
        if n in freq:
            freq[n] += 1
        else:
            freq[n] = 1
    
    # O(n)
    for n in nums:
        if freq[n] == 1:
            return n
    
    return None

def test_firstNonRepeatingInt():
    assert firstNonRepeatingInt([4, 5, 1, 2, 0, 4, 5, 1, 2]) == 0
    assert firstNonRepeatingInt([4, 4, 5, 5, 1, 1, 2, 2]) is None