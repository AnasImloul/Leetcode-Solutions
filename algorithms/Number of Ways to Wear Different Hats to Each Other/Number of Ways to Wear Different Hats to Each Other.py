from functools import cache


class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        # transpose hats
        n_persons = len(hats)
        temp = [[] for _ in range(40)]
        for i, person in enumerate(hats):
            for hat in person:
                temp[hat-1].append(i)
        hats = temp
        
        # drop empty hats and sort
        hats = [h for h in hats if h]
        hats.sort(key=lambda h: len(h))
        n_hats = len(hats)
        
        # helpers
        full = 2 ** n_persons - 1
        bits = [1 << i for i in range(n_persons)]
        cut = 10 ** 9 + 7
        
        
        @cache
        def get_count(i, has_hat):
            if has_hat == full:
                # all persons have a hat
                return 1
            elif i == n_hats:
                # no more hats left
                return 0
            else:
                result = 0
                for person in hats[i]:
                    # does the person 
                    # still not have a hat?
                    if has_hat & bits[person] == 0:
                        # the person wears i-th hat
                        result += get_count(i + 1, has_hat | bits[person])
                # no one wears i-th hat
                result += get_count(i + 1, has_hat)
                
                # return modulo (10 ** 9 - 7)
                return result % cut
        
        
        # start form 0-th hat and 
        # no person wearing a hat
        return get_count(0, 0)
