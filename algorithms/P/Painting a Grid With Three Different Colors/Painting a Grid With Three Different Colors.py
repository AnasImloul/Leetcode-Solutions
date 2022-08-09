class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        from functools import reduce
        MOD = 10**9 + 7
        sum_mod = lambda x,y: (x+y)%MOD
        
        def normalize(pat_var):
            mapping = { e:i+1 for i, e in enumerate(pat_var[0:2]) }
            mapping[list({1,2,3}.difference(mapping.keys()))[0]] = 3
            return tuple([ mapping[e] for e in pat_var])
        
        def get_pats(m, i, pat, pats):
            if i == m-1:
                pats.append(tuple(pat))
                return
            i_nx = i+1
            for p_it_nx in (1,2,3):
                if (i_nx <= 1 and p_it_nx == i_nx+1 ) or (i_nx >= 2 and p_it_nx != pat[-1]):
                    pat.append(p_it_nx)
                    get_pats(m, i_nx, pat, pats)
                    pat.pop()
            return pats
        
        def get_trans(pat, i, pat_pre, trans):
            if i == len(pat)-1:
                pat_nl = normalize(pat_pre)
                trans[pat_nl] = trans.get(pat_nl, 0) + 1
                return
            for p_it_pre in (1,2,3):
                i_nx = i+1
                if (p_it_pre != pat[i_nx]
                    and (not pat_pre or p_it_pre != pat_pre[-1])):
                    pat_pre.append(p_it_pre)
                    get_trans(pat, i_nx, pat_pre, trans)
                    pat_pre.pop()
            return trans

        pats = get_pats(m, -1, [], [])
        # {pattern_i: {pattern_pre:count}}
        pat_trans = { pat: get_trans(pat, -1, [], {}) for pat in pats }  
        
        p_counts = { pat:1 for pat in pat_trans.keys() }
        for i in range(n-1):
            p_counts_new = {}
            for pat, trans in pat_trans.items():
                p_counts_new[pat] = reduce(sum_mod, (p_counts[pat_pre] * cnt for pat_pre, cnt in trans.items()))
            p_counts = p_counts_new
        
        res = reduce(sum_mod, (cnt for cnt in p_counts.values()))
        perms = reduce(lambda x,y: x*y, (3-i for i in range(min(3,m))))
        return (res * perms) % MOD
