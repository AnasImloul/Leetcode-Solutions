	class Solution {
public int[] findDiagonalOrder(List<List<Integer>> nums) {
    HashMap<Integer , Stack<Integer>> map = new HashMap();
    
    for(int i = 0 ; i < nums.size() ; i++){
        for(int j = 0 ; j < nums.get(i).size() ; j++){
            int z = i + j;
            if(map.containsKey(z)){
                map.get(z).add(nums.get(i).get(j));
            }else{
              Stack<Integer> stk = new Stack<>();
                stk.push(nums.get(i).get(j));
                map.put(z , stk);
            }
        }
    }
    ArrayList<Integer> arr = new ArrayList<>();
    int k = 0;
    while(true){
        if(map.containsKey(k)){
            int size = map.get(k).size();
            while(size-- > 0){
                arr.add(map.get(k).pop());
            }
            k++;
        }else{
            break;
        }
    }
    int[] res = new int[arr.size()];
    for(int i = 0 ; i < res.length ; i++){
        res[i] = arr.get(i);
    }
    
    return res;
}}
