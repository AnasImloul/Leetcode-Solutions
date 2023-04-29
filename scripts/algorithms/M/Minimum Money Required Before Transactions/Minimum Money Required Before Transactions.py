class Solution:
    def minimumMoney(self, transactions):
        ans = [max(i-j,0) for i,j in transactions]
        n, max_val, total = len(transactions), 0, sum(ans)

        for i in range(n):
            max_val = max(max_val,total-ans[i]+transactions[i][0])

        return max_val









        


