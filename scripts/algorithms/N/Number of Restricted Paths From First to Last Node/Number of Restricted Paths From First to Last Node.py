class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        
        dct_nd    = {}
        dist_to_n = {}
        queue     = deque() # from n-node to 1-node
        visited   = set()
        
        # 1 step: create dictionary with nodes and nodes' distances to n

        # create dictionary with format (weight, node_to)
        # heap will automatically sort weight and node_to in ascending order
        for l, r, w in edges:
            dct_nd[l] = dct_nd.get(l, []) + [(w, r)]
            dct_nd[r] = dct_nd.get(r, []) + [(w, l)]
        
        dist_to_n[n] = 0
        queue.append(n)
        visited.add(n)
        
        hpf = dct_nd[n].copy()   # without '.copy()' hpf will be only pointer and dct_nd[n] could change
        heapify(hpf)
        while hpf:
            el_w, el_nd = heappop(hpf)
            if el_nd in visited:   continue
            
            dist_to_n[el_nd] = el_w
            visited.add(el_nd)
            queue.append(el_nd)

            if el_nd == 1:         break  # you don't need to traverse more if you've reached 1-node
                                          # other distances will be more than distance of 1-node
            for (i_w, i_nd) in dct_nd[el_nd]:
                if i_nd not in visited:
                    heappush(hpf, (el_w + i_w, i_nd))
        # step 1: end

        # add to dictionary one more field: number of routes to n
        dist_to_n = {k: [v, 0]   for k, v in dist_to_n.items()}
        dist_to_n[n] = [dist_to_n[n][0], 1]  # for n-node number of routes = 1
        
        # step 2: Dynamic Programming
        visited.clear()
        while queue:
            # start from n and traverse futher and futher
            nd_prv = queue.popleft()
            visited.add(nd_prv)
            for (w_cur, nd_cur) in dct_nd[nd_prv]:
                if nd_cur not in visited           and   \
                   nd_cur     in dist_to_n.keys()  and dist_to_n[nd_cur][0] > dist_to_n[nd_prv][0]:
                    # to current node add number of routes from previous node
                    dist_to_n[nd_cur][1] += dist_to_n[nd_prv][1]
                    # !!! careful !!! you need to add modulo operation (as said in the task)
                    dist_to_n[nd_cur][1]  = int(dist_to_n[nd_cur][1] % (1e9+7))
        # step 2: End
        
        return dist_to_n[1][1] # return number of routes for 1-node
