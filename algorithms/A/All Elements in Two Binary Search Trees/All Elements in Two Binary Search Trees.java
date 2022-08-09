    class Solution {
public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
List<Integer> mylist= new ArrayList<>();
   
	there(root1, mylist);
    there(root2, mylist);
    
    int[] arr= new int[mylist.size()];
    for(int i=0; i<arr.length; i++){
        arr[i]=mylist.get(i);
    }
    Arrays.sort(arr);
    List<Integer> now= new ArrayList<>();
    for(int j: arr){
        now.add(j);
    }
    return now;
}
public void there(TreeNode root, List<Integer> map){
if(root==null){
    return;
}
map.add(root.val);
if(root.left!=null){
    there(root.left, map);
}
if(root.right!=null){
    there(root.right, map);
}
}
}
