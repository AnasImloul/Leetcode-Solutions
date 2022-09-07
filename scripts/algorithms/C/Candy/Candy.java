// Runtime: 16 ms (Top 14.09%) | Memory: 53.1 MB (Top 8.48%)
class Solution {
    public int candy(int[] ratings) {

        int[] left = new int[ratings.length];
        Arrays.fill(left, 1);

        // we are checking from left to right that if the element next to our current element has greater rating, if yes then we are increasing their candy
        for(int i = 0; i<ratings.length-1; i++){
            if(ratings[i] < ratings[i+1])
                left[i+1] = left[i]+1;
        }

        int[] right = new int[ratings.length];
        Arrays.fill(right, 1);

        //we are checking from right to left if the element after than our current element is greater or not , if yes then we are also checking their candies if greater rating has less number of candies then increasing their candy
        for(int i = ratings.length -2; i>=0; i--){
            if(ratings[i+1] < ratings[i] && right[i] <= right[i+1])
                right[i] = right[i+1]+1;
        }
        int sum = 0;
        for(int i = 0; i<right.length; i++){
            sum += Math.max(right[i], left[i]);
        }

    return sum;}
}