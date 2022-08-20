# Runtime: 415 ms (Top 31.43%) | Memory: 14.8 MB (Top 57.14%)

class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        trees = sorted(trees, key = lambda e:(e[0],e[1]))
        if len(trees) <= 1:
            return trees
        #checking orientation of vectors oa and ob
        def ccw(o,a,b):
            return (a[0]-o[0])*(b[1]-o[1])-(b[0]-o[0])*(a[1]-o[1]) > 0
        lower_chain = []
        for p in trees:
            while len(lower_chain) > 1 and ccw(lower_chain[-1], lower_chain[-2], p):
                lower_chain.pop()
            lower_chain.append(p)
        upper_chain = []
        for p in reversed(trees):
            while len(upper_chain) > 1 and ccw(upper_chain[-1], upper_chain[-2], p):
                upper_chain.pop()
            upper_chain.append(p)
        return set([(e[0],e[1]) for e in lower_chain[:-1]+upper_chain[:-1]])