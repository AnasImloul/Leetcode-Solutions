class Solution:
    def maxRepOpt1(self, text: str) -> int:
        char_groups = []
        
        for char, group in groupby(text):
            group_len = len(list(group))
            char_groups.append((char, group_len))
        
        char_count = Counter(text)
        
        longest_substr_len = 1 # Each char itself is substring of len 1
        
        # Scenario-1: Get the longest substr length by just adding one more char to each group
        for char, group_len in char_groups:
            # NOTE: If the total count of the char across full string is < group_len+1,
            # make sure to take the total count only
            #
            # It means we don't have any extra char occurrence which we can add to the current group
            
            group_len_w_one_addition = min(group_len+1, char_count[char])
            longest_substr_len = max(longest_substr_len, group_len_w_one_addition)
        
        
        # Scenario-2: 
        # If there are two groups of same char, separated by a group of different char with length=1:
        #   1) We can either swap that one char in the middle with the same char as those two groups 
        #       Ex: 'aaa b aaa c a'
        #           - We can swap the 'b' in between two groups of 'a' using same char 'a' from last index
        #           - So after swapping, it will become 'aaa a aaa c b' 
        #           - hence longest substr len of same char 'a' = 7
        #
        #   2) We can merge the two groups
        #       Ex: 'aaa b aaa' 
        #           -> here there are two groups of char 'a' with len = 3 each.
        #           -> they are separated by a group of char 'b' with len = 1
        #           -> hence, we can merge both groups of char 'a' - so that longest substr len = 6
        #           -> basically, swap the 'b' with 'a' at very last index
        #           -> the final string will look like 'aaaaaa b'
        #
        #   We will take max length we can get from above two options.
        #
        # Since we need to check the group prior to curr_idx "i" and also next to curr_idx "i";
        # we will iterate from i = 1 to i = len(char_groups)-2 -- both inclusive
        
        for i in range(1, len(char_groups)-1):
            prev_group_char, prev_group_len = char_groups[i-1]
            curr_group_char, curr_group_len = char_groups[i]
            next_group_char, next_group_len = char_groups[i+1]
            
            if curr_group_len != 1 or prev_group_char != next_group_char:
                continue
                
            len_after_swapping = min(prev_group_len + next_group_len + 1, char_count[next_group_char])
            longest_substr_len = max(longest_substr_len, len_after_swapping)
        
        return longest_substr_len
