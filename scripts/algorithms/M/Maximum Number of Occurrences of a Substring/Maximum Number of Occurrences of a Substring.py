#   0   1   2   3
#   a   a   a   a
#   l
#   r

#ref: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/discuss/457577/C%2B%2B-Greedy-approach-%2B-Sliding-window-O(n).

#Intuition
#if a string have occurrences x times, any of its substring must also appear at least x times
#there must be a substring of length minSize, that has the most occurrences
#so that we just need to count the occurrences of all substring with length minSize

#Explanation
#find the maximum occurrences of all substrings with length = minSize
class Solution:
    #T=O(n), S=O(n)
    #use sliding window to lock down substrings to minSize limit (greedy approach)
    #then use a counter to count the occurences of valid substrings
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        #dict to store valid substrings and their respective occurences count
        d = defaultdict(int)
        #find longest substrings that has k unique chars
        #counter dict for char count and make sure unique char count is not exceeded
        counter = defaultdict(int)
        #init left and right pointers of sliding window
        r = l = 0
        #iterate right pointer
        while r < len(s):
            counter[s[r]] += 1
            
            #invalid window found, so make it valid again
            #len of window is greater than minSize
            while (r - l + 1) > minSize:
                counter[s[l]] -= 1
                #remove the key from dict for unique char count if it becomes zero
                if counter[s[l]] == 0:
                    del counter[s[l]]
                #increment the left pointer to make it a valid window
                l += 1

            #valid window size (minSize) and unique char count is lesser than or equal to maxLetters
            if r - l + 1 == minSize and len(counter) <= maxLetters:
                #increment count of the occurence of the substring
                d[s[l:r+1]] += 1
            
            #make sure to update right pointer only after an iteration
            r += 1
        
        #return the count of substring with max occurence
        #edge case with no substring
        return max(d.values()) if d else 0
