#!/usr/bin/python
# -*- coding: utf-8 -*-
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:

    def Solve(
        self,
        root,
        val,
        depth,
        curr,
        ):
        if root == None:
            return None
        if depth == 1:
            return TreeNode(val, root)
        if curr == depth - 1:
            (left, right) = (root.left, root.right)
            (root.left, root.right) = (TreeNode(val, left),
                    TreeNode(val, None, right))
            return root
        self.Solve(root.left, val, depth, curr + 1)
        self.Solve(root.right, val, depth, curr + 1)
        return root

    def addOneRow(
        self,
        root,
        val,
        depth,
        ):
        return self.Solve(root, val, depth, 1)
