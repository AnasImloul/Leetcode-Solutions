// Runtime: 454 ms (Top 75.74%) | Memory: 71.3 MB (Top 97.04%)
class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        int n = arr.length;
        Set<Integer> s = new HashSet();
        LinkedList<Integer> queue = new LinkedList();
        for(int i = 0; i< n; i++){
            int size = queue.size();
            if(!queue.contains(arr[i])){
                queue.offer(arr[i]);
                s.add(arr[i]);
            }
            int j = 0;
            while(j<size){
                int tmp = queue.poll()|arr[i];
                if(!queue.contains(tmp)){
                    queue.offer(tmp);
                    s.add(tmp);
                }
                j++;
            }
        }
        return s.size();
    }
}