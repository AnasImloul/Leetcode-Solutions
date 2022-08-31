// Runtime: 6 ms (Top 28.58%) | Memory: 43 MB (Top 43.79%)
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map <Integer, Integer> map = new TreeMap();
        for(int i = 0; i<arr1.length; i++){
            if(map.containsKey(arr1[i])){
                map.replace(arr1[i], map.get(arr1[i]),map.get(arr1[i])+1);
            }
            else{
                map.put(arr1[i], 1);
            }
        }

        int[] arr = new int [arr1.length];
        int ind = 0;
        for(int i = 0; i<arr2.length; i++){

            for(int j = 0; j<map.get(arr2[i]);j++){
                arr[ind] = arr2[i];
                ind++;
            }
            map.remove(arr2[i]);
        }

        for(int i: map.keySet()){

            for(int j = 0; j<map.get(i);j++){
                arr[ind] = i;
                ind++;
            }

        }

        return arr;
    }
}