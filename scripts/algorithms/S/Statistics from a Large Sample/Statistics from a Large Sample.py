class Solution(object):
    def sampleStats(self, count):
        """
        :type count: List[int]
        :rtype: List[float]
        """
        maxv,minv,acc,cnt,mode,modev=None,None,0,0.0,0,0
        for i,n in enumerate(count):
            if minv==None and n!=0:minv=i
            if n!=0:maxv=i
            if n>modev:modev,mode=n,i
            acc,cnt=acc+n*i,cnt+n
          
        midCnt,cc,midv,prei=cnt//2,0,0,i
        for i,n in enumerate(count):
            if n==0:continue
            if cc+n<=midCnt:
                cc,prei=cc+n,i
                continue
            if cnt%2==1:midv=i
            else:midv=(prei+i)/2.0 if cc==midCnt else i
            break
        return (minv,maxv,acc/cnt,midv,mode)   
