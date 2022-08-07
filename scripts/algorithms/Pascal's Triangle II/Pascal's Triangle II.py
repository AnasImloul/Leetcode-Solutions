class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # base case
        # we know that there exist two base case one which is for zero input
        # One when we have to exit our recursive loop 
        if rowIndex == 0:
            return [1]
        if rowIndex == 1:
            return [1,1]
        #recurance relation or prev call
        prev_prob = self.getRow(rowIndex-1)
        # post processing on data 
        # if someone has given us prev_Row what operation we can perform to get current_Row
        return [1]+[prev_prob[i]+prev_prob[i-1] for i in range(1,len(prev_prob))]+[1]
