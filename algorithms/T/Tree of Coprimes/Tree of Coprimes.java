class Solution {
    //made TreeNode class for simple implementation in recurring function
    class TreeNode{
        int id;
        int val;
        List<TreeNode> child;
        public TreeNode(int id,int val){
            this.id=id;this.val=val;child=new ArrayList<>();
        }
    }
    public int[] getCoprimes(int[] nums, int[][] edges) {
        // making tree/graph with edges
        TreeNode[] tr=new TreeNode[nums.length];
        for(int i=0;i<nums.length;i++)tr[i]=new TreeNode(i,nums[i]);
        for(int []x:edges){
            tr[x[0]].child.add(tr[x[1]]);
            tr[x[1]].child.add(tr[x[0]]);
        }
        // intializing answer array of length of tree's nodes which we will return
        int [] ans=new int[nums.length];
        Arrays.fill(ans,-1);
        //creating gcd to not compute gcd everytime
        boolean [][] gcd=new boolean[51][51];
        for(int i=1;i<=50;i++){
            for(int j=i;j<=50;j++){
                if(find_gcd(i,j)==1){
                    gcd[i][j]=true;
                    gcd[j][i]=true;
                }
            }
        }
        int [][] latest= new int[51][2];
		//instead of latest[][] as 2d array we can also use 2 arrays, one for who is latest ancestor & one for storing id
        // in [][0] we will store height of tree so latest ancestor will be called
        // in [][1] we will store id of latest tree
        // initializing all to -1
        for(int i=0;i<=50;i++){latest[i][0]=-1;latest[i][1]=-1;}
        find_closest_ancestor(tr[0],new TreeNode(-1,-1),ans,latest,gcd,0);
        return ans;
    }
    public void find_closest_ancestor(TreeNode root,TreeNode parent, int[] ans,int [][] latest, boolean [][] gcd, int height){
        int val=root.val;
        int latest_id=0;
        for(int i=1;i<=50;i++){
            //if gcd [val][i] is true & latest[i][0] is latest ancestor i.e. it's height is more then save that id
            if(gcd[val][i] && latest[latest_id][0] < latest[i][0])latest_id=i;
        }
        ans[root.id]=latest[latest_id][1];// even if no latest ancestor found latest[id][1] is -1 by default
        
        //this is must we will save before state & after calling all it's child we will make it as it was before calling
        //like backtracking
        int pre_height = latest[val][0],pre_id = latest[val][1];
        latest[val][0]=height;  latest[val][1]=root.id;
        
        // we recur with all child
        for(TreeNode root_child: root.child){
            // we will check if we aren't going upward in tree so root.child!=parent then call function
            if(root_child!=parent)find_closest_ancestor(root_child,root,ans,latest,gcd,height+1);
        }
        //as it was before we will put it back
        latest[val][0]=pre_height;  latest[val][1]=pre_id;
    }
    //simple gcd code
    public int find_gcd(int a, int b){
        if(b==0)return a;
        return find_gcd(b,a%b);
    }
}
