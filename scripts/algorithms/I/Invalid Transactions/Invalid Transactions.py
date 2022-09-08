# Runtime: 451 ms (Top 12.09%) | Memory: 14.8 MB (Top 21.33%)
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        n = len(transactions)
        for i in range(n):
            transactions[i] = transactions[i].split(',')
        transactions.sort(key = lambda x: int(x[1]))
        ans = []
        failed = [False for i in range(n)]
        for i in range(n):
            if int(transactions[i][2]) > 1000 : failed[i] = True
            for j in range(i+1,n):
                if int(transactions[j][1]) - int(transactions[i][1]) > 60: break
                if transactions[j][0] == transactions[i][0] and\
                transactions[j][-1] != transactions[i][-1]:
                    failed[i] = failed[j] = True
            if failed[i] == True:
                ans.append(','.join(transactions[i]))
        return ans
