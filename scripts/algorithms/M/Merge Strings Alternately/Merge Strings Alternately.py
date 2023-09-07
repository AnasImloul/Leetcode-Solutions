# Runtime: 7 ms (Top 98.2%) | Memory: 13.31 MB (Top 45.5%)

class Solution(object):
    def mergeAlternately(self, word1, word2):
        i=0
        j=0
        st=[]
        while i<len(word1) and j<len(word2):
            st.append(word1[i])
            st.append(word2[j])
            i+=1
            j+=1
        while j<len(word2):
            st.append(word2[j])
            j+=1
        while i<len(word1):
            st.append(word1[i])
            i+=1
        return "".join(st)