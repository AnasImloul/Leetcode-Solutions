class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # Initialize variables
        window_start = 0
        max_length = 0
        max_count = 0
        char_count = {}

        # Traverse the string s
        for window_end in range(len(s)):
            # Increment the count of the current character
            char_count[s[window_end]] = char_count.get(s[window_end], 0) + 1
            # Update the maximum count seen so far
            max_count = max(max_count, char_count[s[window_end]])
            
            # Shrink the window if required
            if window_end - window_start + 1 > max_count + k:
                char_count[s[window_start]] -= 1
                window_start += 1
            
            # Update the maximum length of the substring with repeating characters seen so far
            max_length = max(max_length, window_end - window_start + 1)
        
        return max_length
