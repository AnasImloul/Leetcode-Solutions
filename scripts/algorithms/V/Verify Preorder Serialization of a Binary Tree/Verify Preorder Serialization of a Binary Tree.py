# Runtime: 77 ms (Top 11.09%) | Memory: 13.8 MB (Top 99.05%)
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        nodes = preorder.split(',')
        counter=1
        for i, node in enumerate(nodes):
            if node != '#':
                counter+=1
            else:
                if counter <= 1 and i != len(nodes) - 1:
                    return False
                counter-=1
        return counter == 0