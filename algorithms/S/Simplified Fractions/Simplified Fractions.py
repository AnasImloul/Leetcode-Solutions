class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        
        collect = {}
        for b in range(2, n+1):
            for a in range(1, b):
                if a/b not in collect:
                    collect[a/b] = f"{a}/{b}"  
        return list(collect.values())
