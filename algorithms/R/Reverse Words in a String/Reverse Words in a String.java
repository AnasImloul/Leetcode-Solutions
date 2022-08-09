class Solution {
    public String reverseWords(String s) {
        String[] arr = s.replaceAll("\\s{2,}", " ").split(" "); 
        // splitting based on while spaces by replaceing spaces by single gap 
        int n = arr.length;
        String temp = "";
        for(int i =0;i<n/2;i++){
            temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1]=temp;
        }
        String result ="";
        for(int i =0;i<n-1;i++){
            result+=arr[i]+" ";
        }
        result+=arr[n-1];
        return result.trim();
        
    }
}
