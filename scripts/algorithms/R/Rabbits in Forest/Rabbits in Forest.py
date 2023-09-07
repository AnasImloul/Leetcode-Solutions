# Runtime: 54 ms (Top 35.1%) | Memory: 16.38 MB (Top 76.8%)

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        counts = {}
        count = 0

        for answer in answers:
            if answer == 0:
                # This must be the only rabbit of its color.
                count += 1
            elif answer not in counts or counts[answer] == 0:
                # This is the first time the color appears.
                counts[answer] = 1
                # Add all rabbits having this new color.
                count += answer + 1
            else:
                # Add one to how many times answer occurred.
                counts[answer] += 1
                if counts[answer] > answer:
                    # If n+1 rabbits have said n,
                    # this color group is complete.
                    counts[answer] = 0
        
        return count