class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        d={}
        l=[]
        for i in range(len(messages)):
            if senders[i] not in d:
                d[senders[i]]=len(messages[i].split())
            else:
                d[senders[i]]+=len(messages[i].split())
        x=max(d.values())
        for k,v in d.items():
            if v==x :
                l.append(k)
        if len(l)==1:
            return l[0]
        else:
            l=sorted(l)[::-1]      #Lexigograhical sorting of list
            return l[0]
