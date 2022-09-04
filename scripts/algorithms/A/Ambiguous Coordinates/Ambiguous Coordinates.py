# Runtime: 129 ms (Top 6.42%) | Memory: 13.9 MB (Top 92.66%)
class Solution(object):
    def ambiguousCoordinates(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def _isValidSplit(s):
            return False if len(s)>1 and re.match('/^[0]+$/',s) else True

        def _isValidNum(ipart,fpart):
            return False if (len(ipart)>1 and ipart[0]=='0') or (fpart and fpart[-1]=='0') else True

        def _splitToNums(s):
            rets=[]
            if len(s)==1:return [s]
            for i in range(1,len(s)+1):
                a,b=s[:i],s[i:]
                if _isValidNum(a,b):rets.append("%s.%s"%(a,b) if b else "%s"%(a))
            return rets

        ans,s=[],s[1:-1]
        for i in range(1,len(s)):
            a,b=s[:i],s[i:]
            if not _isValidSplit(a) or not _isValidSplit(b):continue
            for c1,c2 in itertools.product(_splitToNums(a),_splitToNums(b)):ans.append("(%s, %s)"%(c1,c2))
        return ans