# Runtime: 4515 ms (Top 5.02%) | Memory: 38.7 MB (Top 5.74%)
from itertools import permutations
class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        # we need begins set to track start letters if word is longer than one to not have them as 0
        begins = {result[0]} if len(result) > 1 else set()

        # the idea to have counter is to sum repeted letters based on where they are in the word

        c = Counter()
        for w in words:
            if len(w) > 1:
                begins.add(w[0])
            for i,l in enumerate(w[::-1]):
                c[l] += 10**i

        # we subtract "result" letters from the counter
        for i,l in enumerate(result[::-1]):
            c[l] -= 10**i

        # we get at the end something like that Counter({'S': 1000, 'E': 91, 'R': 10, 'D': 1, 'Y': -1, 'N': -90, 'O': -900, 'M': -9000})

        # lets split problem into 2 let's check positive letters and negative
        pos = []
        neg = []
        for l, v in c.items():
            if v > 0:
                pos.append( (l,v) )
            elif v < 0:
                neg.append( (l,-v) )

        if not neg and not pos:
            return True

        if not neg or not pos:
            # False if begins else True this one is needed for words with one letter like words = ["A","B"], result = "A"
            return False if begins else True

        NN = len(neg)
        NP = len(pos)

        # we need this one to process permutaion with the smaller number first
        # that would optimize speed
        if NN > NP:
            neg,pos = pos,neg
            NN,NP = NP, NN

        # we create dict with list of sets of permutations
        # keys sum of digit for letter * coefficient
        nd = defaultdict(list)
        for used in permutations(list(range(10)), NN):
            if 0 in used and neg[used.index(0)][0] in begins:
                continue
            nd[sum(v * used[i] for i,(l,v) in enumerate(neg))].append(set(used))

        # same for the other part
        # but while we are doing that we check if overlap of digits is missing
        for used in permutations(list(range(10)), NP):
            if 0 in used and pos[used.index(0)][0] in begins:
                continue
            s = sum(v * used[i] for i,(l,v) in enumerate(pos))
            s1 = set(used)
            if s in nd:
                for s2 in nd[s]:
                    if not s1 & s2:
                        return True

        return False