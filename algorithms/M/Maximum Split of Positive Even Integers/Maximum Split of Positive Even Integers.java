class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> res = new ArrayList<Long>();
        //odd sum cannot be divided into even numbers
        if(finalSum % 2 != 0) {
            return res;
        }
        //Greedy approach, try to build the total sum using minimum unique even nos
        long currNum = 2;
        long remainingSum = finalSum;
        //as long as we can add subtract this number from remaining sum
        while(currNum <= remainingSum) {
            res.add(currNum);
            remainingSum -= currNum;//reducing remaining sum
            currNum += 2;//next even number
        }
        //now, remaining sum cannot be fulfilled by any larger even number
        //so extract the largest even number we added to the last index of res, and make it even larger by adding this current remaining sum
        //add remaining sum to the last element
        long last = res.remove(res.size()-1);
        res.add(last+remainingSum);
        return res;
    }
}
