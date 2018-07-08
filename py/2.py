#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def int2list(val):
    tail = val % 10
    left = int(val / 10)
    root = node = ListNode(tail)
    while left > 0:
        tail = left % 10
        left = int(left / 10)
        node.next = ListNode(tail)
        node = node.next
    return root

def list2int(root):
    val = 0
    while True:
        if root is None:
            break
        print(root.val)
        val += root.val
        root = root.next
    return val

def print_list(root):
    vals = []
    while True:
        vals.append(root.val)
        if root.next is None:
            break
        root = root.next
    s = ' '.join('{} ->'.format(v) for v in vals[:-1])
    s += str(vals[-1])
    s = '({})'.format(s.strip())
    print(s)

def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    inc = 0
    root = None
    # loop to plus
    while True:
        if l1 is None and l2 is None and inc == 0:
            break
        v1 = l1.val if l1 else 0
        v2 = l2.val if l2 else 0
        s = v1 + v2 + inc
        x = s % 10
        curr_node = ListNode(x)
        inc = int(s / 10)
        if root is None:
            root = curr_node
        else:
            prev_node.next = curr_node
        prev_node = curr_node
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    return root


