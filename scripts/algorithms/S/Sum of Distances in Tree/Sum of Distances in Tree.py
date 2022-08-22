# Runtime: 1783 ms (Top 30.42%) | Memory: 59.4 MB (Top 95.18%)
from typing import List

ROOT_PARENT = -1

class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        """
        @see https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C%2B%2BJavaPython-Pre-order-and-Post-order-DFS-O(N)
        :param n:
        :param edges:
        :return:
        """
        g = self.create_undirected_graph(edges, n) # as mentioned in the problem, this graph can be converted into tree

        root = 0 # can be taken to any node between 0 and n - 1 (both exclusive)

        # considering "root" as starting node, we create a tree.
        # Now defining,
        # tree_nodes[i] = number of nodes in the tree rooted at node i
        # distances[i] = sum of distances of all nodes from ith node to all the
        # other nodes of the tree
        tree_nodes, distances = [0] * n, [0] * n

        def postorder(rt: int, parent: int):
            """
            updating tree_nodes and distances from children of rt. To update them, we must know their
            values at children. And that is why post order traversal is used

            After the traversal is done,
                tree_nodes[rt] = all the nodes in tree rooted at rt
                distances[rt] = sum of distances from rt to all the nodes of tree rooted at rt

            :param rt:
            :param parent:
            """
            tree_nodes[rt] = 1

            for c in g[rt]:
                if c != parent:
                    postorder(c, rt)

                    # adding number of nodes in subtree rooted at c to tree rooted at rt
                    tree_nodes[rt] += tree_nodes[c]

                    # moving to rt from c will increase distances by nodes in tree rooted at c
                    distances[rt] += distances[c] + tree_nodes[c]

        def preorder(rt: int, parent: int):
            """
            we start with "root" and update its children.
            distances[root] = sum of distances between root and all the other nodes in tree.

            In this function, we calculate distances[c] with the help of distances[root] and
            that is why preorder traversal is required.
            :param rt:
            :param parent:
            :return:
            """
            for c in g[rt]:
                if c != parent:
                    distances[c] = (
                            (n - tree_nodes[c]) # rt -> c increase this much distance
                            +
                            (distances[rt] - tree_nodes[c]) # rt -> c decrease this much distance
                    )
                    preorder(c, rt)

        postorder(root, ROOT_PARENT)
        preorder(root, ROOT_PARENT)

        return distances

    @staticmethod
    def create_undirected_graph(edges: List[List[int]], n: int):
        """
        :param edges:
        :param n:
        :return: graph from edges. Note that this undirect graph is a tree. (Any node can be
                 picked as root node)
        """
        g = [[] for _ in range(n)]

        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        return g