class Solution {
    public int nextGreaterElement(int n) {
        char[] arr = (n + "").toCharArray();
        
        int i = arr.length - 1;
        while(i > 0){
            if(arr[i-1] >= arr[i]){
                i--;
            }else{
                break;
            }
        }
        if(i == 0){
            return -1;
        }
        
        int idx1 = i-1;
        
        int j = arr.length - 1;
        while(j > idx1){
            if(arr[j] > arr[idx1]){
                break;
            }
            j--;
        }
        
        //Swapping
        swap(arr,idx1,j);
        
        //sorting
        int left = idx1+1;
        int right = arr.length-1;
        while(left < right){
            swap(arr,left,right);
            left++;
            right--;
        }
        
        String result = new String(arr);
        long val = Long.parseLong(result);
        
        return (val > Integer.MAX_VALUE ? -1 : (int)val);
        
    }
    
    void swap(char[]arr,int i,int j){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

