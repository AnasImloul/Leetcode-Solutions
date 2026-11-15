# Runtime: 14 ms (Top 81.62%) | Memory: 19.40 MB (Top 22.79%)

class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:

        isTen1 = isTen2 = wasTen1 = wasTen2 = False
        diff = 0

        for n1, n2 in zip(player1, player2):

            diff+= (1+(wasTen1|isTen1))*n1 - (1+(wasTen2|isTen2))*n2

            isTen1,isTen2, wasTen1, wasTen2 = n1 == 10, n2 == 10,isTen1,isTen2 

        return  (diff < 0) + (diff != 0)
