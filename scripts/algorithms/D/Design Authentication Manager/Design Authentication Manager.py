# Runtime: 732 ms (Top 5.07%) | Memory: 15.5 MB (Top 65.88%)
class AuthenticationManager(object):

    def __init__(self, timeToLive):
        self.token = dict()
        self.time = timeToLive # store timeToLive and create dictionary

    def generate(self, tokenId, currentTime):
        self.token[tokenId] = currentTime # store tokenId with currentTime

    def renew(self, tokenId, currentTime):
        limit = currentTime-self.time # calculate limit time to filter unexpired tokens
        if tokenId in self.token and self.token[tokenId]>limit: # filter tokens and renew its time
            self.token[tokenId] = currentTime

    def countUnexpiredTokens(self, currentTime):
        limit = currentTime-self.time # calculate limit time to filter unexpired tokens
        c = 0
        for i in self.token:
            if self.token[i]>limit: # count unexpired tokens
                c+=1
        return c