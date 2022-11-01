// Runtime: 1 ms (Top 92.18%) | Memory: 44.7 MB (Top 72.44%)

/*

1. Generate Right min
2. Generate Left Max
3. Count chunks

Pos -->. 0 1 2 3 4 5 6 7

Input --> 30 , 10 , 20 , 40 , 60 , 50 , 75 , 70
             <------------> <--> <-------> <------->
Left Max --> 30 , 30 , 30 , 40 , 60 , 60 , 75 , 75

Right Min --> 10 , 10 , 20 , 40 , 50 , 50 , 70 , 70 , Integer.max

1. At pos 2 , left_max 30 is smaller than right_min 40 at pos 3
2. That means , all the elements in the right side of 30 are bigger than all the elements of left side of 30 , including 30
3. Hence we can break it at pos 2 into a chunk and sort this whole sub-array( 0 - 2 )

*/

class Solution {

    public int maxChunksToSorted(int[] arr) {

        // 1. Generate Right min

        int[] min_from_right = new int[arr.length+1] ;
        min_from_right[arr.length] = Integer.MAX_VALUE ;

        for(int i=arr.length-1 ; i>=0 ; i--){
            min_from_right[i] = Math.min(arr[i] , min_from_right[i+1]);
        }

        // 2. Generate Left Max and Count chunks
        int chunk_count = 0 ;
        int max_cur = Integer.MIN_VALUE ;

        for(int i=0 ; i<arr.length ; i++){
            max_cur = Math.max(max_cur , arr[i]);
            if(max_cur <= min_from_right[i+1]){
                chunk_count++ ;
            }
        }

        return chunk_count ;
    }
}
