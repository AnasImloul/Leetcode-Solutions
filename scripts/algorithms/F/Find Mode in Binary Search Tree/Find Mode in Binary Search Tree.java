// Runtime: 8 ms (Top 17.7%) | Memory: 45.06 MB (Top 9.4%)

class Solution {
    public int[] findMode(TreeNode root) {
        if(root==null) return new int[0];
        Map<Integer, Integer> map = new HashMap<Integer, Integer>(); //we are taking map to count each and every value of the tree and the no of times they occurs in the tree
        Queue<TreeNode> qu = new LinkedList<TreeNode>(); // to itereate over the tree
        List<Integer> list = new ArrayList<Integer>(); //to save our result into a dynamic arraylist then will convert into static array for return it
        qu.add(root);                     // add the first root node into queue to iterate over the tree
        while(!qu.isEmpty()) {   
            TreeNode tmp = qu.poll();               //we poll out the node which is last inputed to the queue
            if(map.containsKey(tmp.val)) {           //we are checking through the map wheather the value this node have already stored into the map or not
                map.put(tmp.val, map.get(tmp.val)+1);     //the value is already stored then we just increase the count by 1
            }
            else {
                map.put(tmp.val, 1);     //if the value is unique then we store it to the map with the count 1
            }
            if(tmp.left!=null) qu.add(tmp.left);    //this way we are checking wheather left node has any value or not respect to the current poped element of queue
            if(tmp.right!=null) qu.add(tmp.right);    //the same thing of the above just this is for right node of respective poped out node
        }
        int max = Integer.MIN_VALUE;   //we are taking it because of requirement to identify highest no of repeated node available in this tree 
        for(Integer key : map.keySet()) {  //we are using keySet() for iterating over the map here key is differernt nodes and value is the no of count they have in this tree
            if(map.get(key)>max) { //if anything we find have greater value then previous maximum no of node like 2 2 2 - value 3, 3 3 3 3 - value 4 so now 4 is the maximum now 
                list.clear(); //just to clear previous data that are stored into that list
                max = map.get(key);   //now max will replaced by the new no of count of a node
                list.add(key);    //we are adding the key which has most no of count
            }
            else if(max==map.get(key)) { //if we found another node which also has present maximum no of node count in the tree
                list.add(key);  //we are also adding those key
            }
        }
		//now we just create an array transfer hole data that arraylist has and then return
        int[] res = new int[list.size()];
        for(int i=0; i<list.size(); i++) {
            res[i] = list.get(i);
        }
        return res;
    }
}