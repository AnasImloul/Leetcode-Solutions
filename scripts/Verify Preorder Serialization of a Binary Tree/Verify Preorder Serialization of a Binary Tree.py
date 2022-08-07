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
