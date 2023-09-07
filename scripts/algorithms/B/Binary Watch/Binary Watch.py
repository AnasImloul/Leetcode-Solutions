# Runtime: 44 ms (Top 50.1%) | Memory: 16.36 MB (Top 42.0%)

class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        output = []
        # Loop through all possible combinations of hours and minutes and count the number of set bits
        for h in range(12):
            for m in range(60):
                if bin(h).count('1') + bin(m).count('1') == turnedOn:  # Check if the number of set bits in hours and minutes equals the target number
                    output.append(f"{h}:{m:02d}")  # Add the valid combination of hours and minutes to the output list
        return output
