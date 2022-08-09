class Solution:
    count = 0  # Found candy. Class variable to keep found candy
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        boxes = []  # Newly found boxes
        progress = False
        for box in initialBoxes:
            if status[box]:  # The box is open
                progress = True
                boxes.extend(containedBoxes[box])  # Add newly found boxes
                self.count += candies[box]  # Count found candy
                for key in keys[box]:
                    status[key] = 1  # Use found keys to open boxes even if we don't have them.
            else:
                boxes.append(box)  # The box is closed. Keep it for the next iteration.
        if not progress:  # Nothing happened. return.
            return self.count
		# Run another iteration with the new 'boxes'
        return self.maxCandies(status, candies, keys, containedBoxes, boxes)
