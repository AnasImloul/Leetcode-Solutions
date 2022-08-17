
/* Intuition:
As the number of elements is 10^9 so we can't actually create the array
And by seeing the limit we can judge that the complexity should be O(logn)
So it will become obvious that binary search can only help to solve this prob

We have to put the maximum possible value in the index position and then all 
the values to its right and left should decrease by 1 until the value reaches 1
for Ex in n = 6, index = 1,  maxSum = 10

our index at 1 should be 3 and the array will look like
2  3  2 1 1
+ max - - same

means you have to make an array which is strictly increasing and it attains its max (which is answer)
then strictly decreasing till value becomes 1 and then continues it as 1. Like
1 ... 1, 2, 3, 4, 5, 6(if answer is 6), 5, 4, 3, 2, 1, .... 1

Why this solution?
Because our objective is to maximize our index position value i.e. ans. So to maximize it
we all the other elements other than index position should be as low as possible (so that sum of our array
is less than maxSum), which will lead to this solution of "Get the max element on index given and decrease strictly
on both sides of the array till our value is 1, and then continue it to 1"
*/

class Solution {
    public int maxValue(int n, int index, int maxSum) {
        // Setting the initial values is very important, our ans can never be 0 so set low as 1
        int low = 1, mid = 0, high = 1000000000;
        while(low <= high) {
            mid = (low + high) / 2;
            
            // If our ans (which is mid) is making the sum of array more than maxSum means we have to decrease our high
            if(calcAns(mid, index, n) > maxSum) { 
                high = mid - 1;
            } 
            
            // If our ans (which is mid) is so low that even ans + 1 (i.e. mid + 1) is giving better result that means increase our low
            else if(calcAns(mid + 1, index, n)  <= maxSum) {
                low = mid + 1;
            } 
            
            // If our ans (== mid) is such that the sum of array is less than maxSum and even increasing 1 to mid will result the total
            // sum to increase from maxSum, that signifies that we have the answer as mid
            else {
                break;
            }
        }
        
        return mid;
    }
    
    public int calcAns(int max, int idx, int n) {
        
        // This method will give you answer of the setup where our peak element is ans at index idx and we have n elements
        // So we have two part of array one is the left part (1, 1... 2, 3 ... max - 1) and then (max, max - 1, max - 2, 1 ... 1)
        // so you can think of it as we have few extraOnes on both left and right parts and then an AP array which goes upto max
        
        // Left part I have taken till max - 1 and right part I have taken from max.
        // calcPart takes (first value of AP, number of elements)
        
        long ret = calcPart(max - 1, idx) + calcPart(max, n - idx);
        if(ret > 1000000000) {
            // Seeing the constraints, if you chose to take high mid value then it might overflow from int. And our answer can never
            // be greater than 10^9 so limit it to that.
            return 1000000001;
        } else {
            
            // This is the sum of the array where max is taken as answer
            return (int)ret;
        }
    }
    
    public long calcPart(int a, int num) {
        
        // For AP we need first element (which is "a") and last element (which we calculate in an)
        long an = 0, extraOnes = 0;
        long ans = 0;
        if(num >= a) {
            
            // If total number of elements is more than a which means it will look like
            // a, a - 1, a - 2,  ... , 2, 1 ... followed by extraOnes
            an = 1;
            extraOnes = num - a;
        } else if(num < a) {
            
            // If total number of elements is such that we never reach 1 as our last element means
            // a, a - 1, a - 2 ... a - x, then extraOnes will be 0
            extraOnes = 0;
            an = a - num + 1;
        }
        
        // Sum of AP where we know first and last element = ((first + last) * n) / 2
        ans = ((an + a) * (a - an + 1)) / 2;
        
        // Add extra ones
        ans += extraOnes;
        
        return ans;
    }
}
