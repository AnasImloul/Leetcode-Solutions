# Runtime: 74 ms (Top 53.33%) | Memory: 20.10 MB (Top 36.00%)

class Solution:

    def insertAndRemove(self, mp, toInsert, toRemove): 
        mp[toInsert]+=1
        mp[toRemove]-=1

        if(mp[toRemove]==0):
            del mp[toRemove]     # if freq of that char reaches zero, then remove the key from dict


    def isItPossible(self, word1: str, word2: str) -> bool:

        mp1, mp2 = Counter(word1), Counter(word2)  # Get freq of chars using Counter

        """
        # If you are not familiar with Counters, you can simply do this:
        mp1=defaultdict(int)
        mp2=defaultdict(int)

        for w1 in word1:
            mp1[w1]+=1;   #store freq of chars in word1 in mp1

        for w2 in word2:
            mp2[w2]+=1;  #store freq of chars in word2 in mp2
        """

        for c1 in string.ascii_lowercase:         # this for loop iterates through c1='a' to c1='z'
            for c2 in string.ascii_lowercase:     # this for loop iterates through c2='a' to c2='z'

                if c1 not in mp1 or c2 not in mp2:  # if any of the char is not present then skip
                    continue

                self.insertAndRemove(mp1, c2, c1); # insert c2 to word1 and remove c1 from word1
                self.insertAndRemove(mp2, c1, c2); # insert c1 to word2 and remove c2 from word2

                if len(mp1)== len(mp2):  # if size of both dicts are equal then possible return true
                    return True

                # reset back the maps
                self.insertAndRemove(mp1, c1, c2); # insert c1 back to word1 and remove c2 from word1         
                self.insertAndRemove(mp2, c2, c1); # insert c2 back to word2 and remove c1 from word2                
        return False
