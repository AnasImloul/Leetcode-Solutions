// Runtime: 1158 ms (Top 100.0%) | Memory: 67.00 MB (Top 59.7%)

class Solution:
    def minimumMoney(self, transactions: list[list[int]]) -> int:
        # First, split and sort the input "transactions" per the hint
        incomers = [transaction for transaction in transactions if transaction[0] <= transaction[1]]
        outgoers = [transaction for transaction in transactions if transaction[0] > transaction[1]]
        incomers.sort(key=lambda transaction: transaction[0], reverse=True)
        outgoers.sort(key=lambda transaction: transaction[1])

        # Second, process "outgoers", transactions where cost > cashback:  The question is:  how
        # much money do we need up front in order to complete processing of
        # the outgoers.   The latter amount is the sum of the net cost of all but the last
        # transaction plus the cost of the last transaction.
        if outgoers:
            outgoer_cost = sum(map(lambda transaction: transaction[0] - transaction[1], outgoers) )
            assert outgoer_cost > 0
            min_ante = outgoer_cost + outgoers[-1][1]
            after_outgoers = min_ante - outgoer_cost
        # What this means:  If we start with "min_ante", we can process all the "outgoers" and
        # end up with "after_outgoers".
        else:
            min_ante = 0
            after_outgoers = 0

        # Third, process the "incomers", transactions where cashback is >= cost.  I *think* it's enough
        # to have enough cash on hand to satisfy the first "cost" since then, by construction, we'll
        # have enough for all subsequent "incomers".
        if incomers:
            min_incomer_available = incomers[0][0]
        else:
            min_incomer_available = 0

        # Fourth, put together the two components:
        if min_incomer_available > after_outgoers:
            min_ante += min_incomer_available - after_outgoers
        return min_ante
