#!/usr/bin/env python
# -*- coding: utf-8 -*-
def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int

    i, j are both indices.
    """
    N = len(s)
    # init
    i, j = 0, 0
    n_max = 0
    pos = {}
    # loop
    while j < N:
        # make valid
        c = s[j]
        if c in pos and pos[c] >= i:
            i = pos[c] + 1
        pos[c] = j
        n = j - i + 1
        if n > n_max:
            n_max = n
        # move j forward
        j += 1
    return n_max

def test_1():
    s = 'abcabcbb'
    assert lengthOfLongestSubstring(s) == 3

def test_2():
    s = 'bbbbb'
    assert lengthOfLongestSubstring(s) == 1

def test_3():
    s = 'pwwkew'
    assert lengthOfLongestSubstring(s) == 3

def test_4():
    s = ''
    assert lengthOfLongestSubstring(s) == 0

