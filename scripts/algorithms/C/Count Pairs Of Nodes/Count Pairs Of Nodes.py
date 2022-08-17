class Solution:
    def countPairs(self, n: int, edges: List[List[int]], queries: List[int]) -> List[int]:
        p_c = [0] * (n+1) # point counter
        e_c = defaultdict(int) # edge counter
        
        for a,b in edges:
            p_c[a] += 1
            p_c[b] += 1
            if a<b:
                e_c[(a,b)] += 1
            else:
                e_c[(b,a)] += 1
        
        f_c = defaultdict(int) # frequency of point counter (compress the individual calculations into massive one)
        for i in range(1, n+1):
            f_c[p_c[i]] += 1

        cnt_amt = defaultdict(int) # frequency of same cnt on pairs without edge adjustment
        f_key = list(f_c.keys()) # frequency key
        l_f = len(f_key)
        for i in range(l_f):
            f1 = f_key[i]
            cnt_amt[f1*2] += f_c[f1] * (f_c[f1]-1) // 2 # 3 points with 4, then you get 8 
                                                        # for a frequency of 3 * (3-2) // 2 = 3
            for j in range(i+1, l_f):
                f2 = f_key[j]
                cnt_amt[f1+f2] += f_c[f1] * f_c[f2] # 2 points with 2, 3 points with 4
                                                    # will have 6 with frequency of 2 * 3 = 6
        
        for (u,v), z in e_c.items(): # edge adjustment
            s = p_c[u] + p_c[v]
            t = s - z
            cnt_amt[s] -= 1
            cnt_amt[t] += 1
        
        cnt_keys = sorted(cnt_amt.keys(), key=lambda x: -x) # accumulate the frequency by descending order
        res = defaultdict(int)
        tmp = 0
        for key in cnt_keys:
            if cnt_amt[key]: # if it is 0 then dont bother to keep them
                tmp += cnt_amt[key]
                res[key] = tmp

        res_keys = sorted(res.keys()) # bisection search 
        for i, q in enumerate(queries):
            local = bisect.bisect(res_keys, q)
            try:
                queries[i] = res[res_keys[local]]
            except:
                queries[i] = 0 # some test cases are annoying by requesting an unreasonable large number
        
        return queries
