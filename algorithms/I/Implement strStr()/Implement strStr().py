class Solution(object):
    def strStr(self, haystack, needle):
        if needle == '':
            return 0
        else:
            return self.search_substring(haystack, needle)

    def search_substring(self, haystack, needle):
        len_substring = len(needle)
        for i in range(len(haystack)):
            if haystack[i: i + len_substring] == needle:
                return i
        return -1
