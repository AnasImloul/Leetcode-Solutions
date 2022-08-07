class Solution:
    def restoreIpAddresses(self, s: str):
        def isValid(st):
            if(len(st)!=len(str(int(st)))):
                return False
            st = int(st)
            if(st>255 or st<0):
                return False
            return True
        
        validIps = []
        for i in range(1,4):
            s1 = s[:i]
            if(not isValid(s1)):
                continue
            for j in range(i+1, min(len(s), i+4)):
                s2 = s[i:j]
                if(not isValid(s2)):
                    continue
                for k in range(j+1,min(len(s), j+4)):
                    s3 = s[j:k]
                    if(not isValid(s3)):
                        continue
                    s4 = s[k:]
                    if(not isValid(s4)):
                        continue
                    currentIp = s1+"."+s2+"."+s3+"."+s4
                    validIps.append(currentIp)
        return validIps
