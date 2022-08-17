class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> l = new ArrayList<Integer>();
        int i=0;
        int len = (int)Math.pow(2,n);
        int[] arr = new int[len];
        while(i<len){
            arr[i]=(i)^(i/2);
            i++;
        }
        
        i=0;
        while(arr[i]!=start)i++;
        while(i<arr.length){
            l.add(arr[i]);
            i++;
        }
        i=0;
        while(i<arr.length && arr[i]!=start){
            l.add(arr[i]);
            i++;
        }
        return l;
    }
}
