class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        def merge(accounts):
            res = []
            ls = []
            for i in range(len(accounts)):
                temp = list(set(accounts[i][1:]))
                temp.sort()
                temp = [accounts[i][0]] + temp
                if i in ls:
                    continue
                for j in range(len(accounts[i:])):
                    s = i+j
                    if i == s:
                        continue
                    if accounts[i][0] != accounts[s][0]:
                        continue
                    temp3 = list(set(accounts[s][1:]))
                    uni = list(set(temp[1:]) | set(temp3))
                    if len(uni) < len(temp[1:]) + len(temp3):
                        temp1 = list(set(temp[1:]) | set(temp3))
                        temp = [temp[0]] + temp1 
                        ls.append(s)
                temp0 = temp[1:]
                temp0.sort()
                temp = [temp[0]]+temp0
                res.append(temp)
            return res
        merged = merge(accounts)
        while merge(merged) != merged:
            merged = merge(merged)

        return merged
