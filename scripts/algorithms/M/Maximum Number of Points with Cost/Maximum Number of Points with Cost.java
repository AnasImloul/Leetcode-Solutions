/* 
   -> take a frame same width as points,this frame will contains most effective(which provide maximum sum)values which will later get 
	added to next values from next row.

   -> conditions to update values in frame 
		* we will keep only those values which will contribute maximum in next row addition

	e.g-->
		points --->[[1,2,3]
					[1,5,1]
					[3,1,1]]

		for 1st iteration frame <--- [1,2,3] rest of two loops will not affect frame so in 
		2nd itreration frame <--------[2,7,4] <-------- [1,2,3] + [1,5,1]
		now we have to update frame so it can give max values for next row addition
		 0 1 2   
		[2,7,4] 
		  \ 
		[2,7,4]  check left to right--> just check value at index 0 can contribute more than curr_sum at index 1 but to do so it has to give up (1-0) a penalty,here 7 can contribute more than 2-1=1 in next sum.
		2 7 4        now check for index 2,where (7-1)>4
		   \
		2 7 6
					now do in reverse,can 6 contribute more than 7 no ( 7 >(6-1) )  
					can 7 contibute more than 2 yes (2<(7-1)),so now  frame will be
		6 7 6       now we can cal optimal-frame for rest of the matrix.
	+   3 1 1
 ------------------- 
		9 8 7  check left to right--> can 9 can contibute 8>(9-1) no; can 8 can contibute for index 2 no simlier for right to left
*/

class Solution {
	public long maxPoints(int[][] points) {
		long[] frame = new long[points[0].length];

		for (int i = 0; i < points.length; i++) {
			for (int j = 0; j <frame.length; j ++) frame[j] += points[i][j];

			for (int j = 1; j < frame.length; j ++) frame[j] = Math.max(frame[j], frame[j - 1] - 1);

			for (int j=frame.length-2;j>=0;j--) frame[j] = Math.max(frame[j], frame[j + 1] - 1);

			for(long k:frame) System.out.println(k);
		}


		long ans = 0;
		for (int i = 0; i < frame.length; i ++) {
			ans = Math.max(ans, frame[i]);
		}
		return ans;
	}
}
