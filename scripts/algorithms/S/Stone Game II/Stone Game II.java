// Runtime: 884 ms (Top 5.06%) | Memory: 117.5 MB (Top 5.06%)
class Solution {
    public int stoneGameII(int[] piles) {
        Map<String, Integer> memo = new HashMap<>();
        int diff = stoneGame(piles,1,0,0,memo);
        int totalSum = 0;
        for(int ele: piles)
            totalSum+=ele;
        return (diff+totalSum)/2;
    }

    public int stoneGame(int[] piles, int M, int index, int turn,Map<String, Integer> memo )
    {
        if(index >= piles.length)
            return 0;
        if(memo.containsKey(index+"-"+M+"-"+turn))
            return memo.get(index+"-"+M+"-"+turn);
        int score=0,maxScore=Integer.MIN_VALUE;
        // Alice's turn
        if(turn == 0)
        {
            for(int X=1;X<=2*M && index+X-1<piles.length;X++)
            {
                score += piles[index+X-1];
                maxScore= Math.max(maxScore,stoneGame(piles,Math.max(X,M),index+X,1,memo)+score);
            }
            memo.put(index+"-"+M+"-"+turn,maxScore);
            return maxScore;
        }
        // Bob's turn
        int minScore=Integer.MAX_VALUE;
        for(int X=1;X<=2*M && index+X-1<piles.length;X++)
        {
            score += piles[index+X-1];
            minScore = Math.min(minScore, stoneGame(piles,Math.max(X,M),index+X,0,memo) - score ) ;
        }
        memo.put(index+"-"+M+"-"+turn,minScore);
        return minScore;
    }

}