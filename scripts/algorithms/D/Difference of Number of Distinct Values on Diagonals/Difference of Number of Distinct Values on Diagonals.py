# Runtime: 177 ms (Top 85.5%) | Memory: 16.58 MB (Top 51.9%)

class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:

        d = defaultdict(list)                      

        for i, j in product(range(len(grid)),        
                            range(len(grid[0]))):
            d[i-j].append((i,j))                        # <-- Construct dict of diagonals; i - j
                                                        #     remains constant on a '\' diag. 
        for diag in d:
            arr = [grid[i][j] for i,j in d[diag]]       # <-- Construct an arr of the elements
                                                        #     on the diagonal.

            for idx, (i,j) in enumerate(d[diag]):       # <-- Overwrite each element in the diagonal.   
                grid[i][j] = abs(len(set(arr[:idx])) -  #     in the array with its score.
                                 len(set(arr[idx+1:])))
            
        return grid                                     # <-- Return the overwritten 'grid' as the
                                                        #     'answer' matrix.