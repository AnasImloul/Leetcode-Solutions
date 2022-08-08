class Solution {
    public TreeNode recoverFromPreorder(String traversal) {
        if(!traversal.contains("-"))
            return new TreeNode(Integer.parseInt(traversal));
        String number = "";
        int i = 0;
        while(traversal.charAt(i)!='-'){
            number+=traversal.charAt(i);
            i++;
        }
        //System.out.print("root = " + number + " " + i + "     ");
        TreeNode root = new TreeNode(Integer.parseInt(number));
        StringBuilder str = new StringBuilder();
        int bk = 0;
        for(int j = i; i < traversal.length(); i++){
            if(traversal.charAt(i-1) != '-' && traversal.charAt(i) == '-' && traversal.charAt(i+1) != '-')
                bk = str.toString().length();
            else if(!(traversal.charAt(i-1) != '-' && traversal.charAt(i) == '-'))
                str.append(traversal.charAt(i));
        }
        String divide = str.toString();
        
        TreeNode left = (bk==0)?recoverFromPreorder(divide):recoverFromPreorder(divide.substring(0,bk));
        TreeNode right = (bk==0)?null:recoverFromPreorder(divide.substring(bk,divide.length()));
        root.left = left;
        root.right = right;
            
        
        return root;
    }
}
