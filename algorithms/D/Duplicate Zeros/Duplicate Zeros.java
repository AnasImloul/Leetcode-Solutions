class Solution {
    
    //  Time Complexity = O(n)
    //  Space Complexity = O(1)
    
    public void duplicateZeros(int[] arr) {
        
        //  Loop through the array
        for(int i = 0; i < arr.length; i++) {
        
        //  Trigger Condition     
            if(arr[i] ==0) {
                int j;      // auxilliary variable for swapping 
                for(j = arr.length-2; j>=i+1; j--) {
                    arr[j+1] = arr[j];      //  Shift each element by one space
                }
                arr[j+1] = 0;               //  Duplicating the zero on the consecutive index of i
                i++;                        //  Skipping the duplicated zero index in the array 
            }
        }
    }       
}
