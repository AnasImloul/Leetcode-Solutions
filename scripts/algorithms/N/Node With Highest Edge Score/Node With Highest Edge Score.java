// Runtime: 82 ms (Top 21.01%) | Memory: 73.90 MB (Top 5.07%)

class Solution {
    public int edgeScore(int[] edges) {
        //Creating a Hashmap
        HashMap<Integer,List<Integer>> map=new HashMap<Integer,List<Integer>>();
        //Score variable for keeping track of highest edge score
        long score=Integer.MIN_VALUE;
        //Index variable for storing answer
        int index=Integer.MAX_VALUE;
        for(int i=0;i<edges.length;i++){
            //If map does not contains Key then putting it to the hashmap
            if(!map.containsKey(edges[i])){
                List<Integer> list=new ArrayList<Integer>();
                list.add(i);
                map.put(edges[i],list);
            }
            //If map contains Key then adding the node directing to it in the list
            else{
                List<Integer> list=map.get(edges[i]);
                list.add(i);
            }
        }
        
        //HashMap contains nodes as key and value as list which contains all directing node to key node
        for(int key:map.keySet()){
            //Initializing a list which stores all nodes directing to key node
            List<Integer> list=map.get(key);
            long sum=0;
            //Taking sum of all directing nodes in sum variable
            for(int node:list){
                sum+=node;
            }
            //If sum>score then updating the score and iindex
            if(sum>score){
                score=sum;
                index=key;
            }
            //If sum==score then updating index with the smaller value from index and key
            else if(sum==score){
                index=Math.min(index,key);
            }
        }
        return index;
    }
}
