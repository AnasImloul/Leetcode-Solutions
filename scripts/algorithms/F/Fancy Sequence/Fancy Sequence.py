def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    return x % m

mod = 1000000007

class Fancy(object):

    def __init__(self):
        self.seq = []
        self.addC = 0
        self.mulC = 1
        
    def append(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.seq.append([val, self.mulC, self.addC])
        

    def addAll(self, inc):
        """
        :type inc: int
        :rtype: None
        """
        self.addC = (self.addC%mod + inc%mod)%mod

    def multAll(self, m):
        """
        :type m: int
        :rtype: None
        """
        self.mulC = (self.mulC%mod * m%mod)%mod
        self.addC = (self.addC%mod * m%mod)%mod
        

    def getIndex(self, idx):
        """
        :type idx: int
        :rtype: int
        """
        if(idx >= len(self.seq)):
            return -1
        
        mulCo = self.seq[idx][1]
        addCo = self.seq[idx][2]
        val = self.seq[idx][0]
        
        inv = modinv(mulCo, mod)
        a = (self.mulC%mod * inv%mod)%mod
        val = (val%mod * a%mod)%mod
        b = (addCo%mod * a%mod)%mod
        val = (val%mod - b%mod)%mod
        val = (val%mod + self.addC%mod)%mod
        
        return val
