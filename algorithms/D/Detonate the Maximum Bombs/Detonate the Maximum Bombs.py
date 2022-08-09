class Solution(object):
    def maximumDetonation(self, bombs):
        def count(i):
            dq, ret = [i], [i]
            while len(dq) > 0:
                i = dq.pop()
                for j in adj[i]:
                    if j not in ret and j not in dq:
                        dq.append(j)
                        ret.append(j)
            return len(ret)

        adj = collections.defaultdict(list)
        for i in range(len(bombs)):
            for j in range(i + 1, len(bombs)):
                if (bombs[i][0] - bombs[j][0]) ** 2 + (bombs[i][1] - bombs[j][1]) ** 2 <= bombs[i][2] ** 2:
                    adj[i].append(j)
                if (bombs[i][0] - bombs[j][0]) ** 2 + (bombs[i][1] - bombs[j][1]) ** 2 <= bombs[j][2] ** 2:
                    adj[j].append(i)
        ret = 0
        for i in range(len(bombs)):
            ret = max(ret, count(i))
        return ret
