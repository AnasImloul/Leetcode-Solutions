class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        st,sp=[],[]
        for i,ch in enumerate(s):
            if ch.isalpha():
                st.append(ch)
            else:
                sp.append([i,ch])
        st=st[::-1]
        for i in sp:
            st.insert(i[0],i[1])
        return (''.join(st))