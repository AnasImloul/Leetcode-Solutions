class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        visited_time = [0] * n
        inpath = [False] * n
        cur_time = 1
        def get_max_len_cycle(cur) :
            nonlocal cur_time
            inpath[cur], visited_time[cur], nxt = True, cur_time, favorite[cur]
            cur_time += 1
            ret = 0 if not inpath[nxt] else visited_time[cur] - visited_time[nxt] + 1
            if visited_time[nxt] == 0 : ret = max(ret, get_max_len_cycle(nxt))
            inpath[cur] = False
            return ret
        
        ret_cycle = 0
        for i in range(n) :
            if visited_time[i] == 0 :
                ret_cycle = max(ret_cycle, get_max_len_cycle(i))
        
        ret_not_cycle = 0
        back_edge_graph = [[] for _ in range(n)]
        for i in range(n) : back_edge_graph[favorite[i]].append(i)
        def get_max_depth(cur) :
            ret = 0
            for nxt in back_edge_graph[cur] :
                if favorite[cur] != nxt :
                    ret = max(ret, get_max_depth(nxt) + 1)
            return ret
        
        for i in range(n) :
            if favorite[favorite[i]] == i : ret_not_cycle += get_max_depth(i) + 1
        
        ret = max(ret_cycle, ret_not_cycle)
        return ret
