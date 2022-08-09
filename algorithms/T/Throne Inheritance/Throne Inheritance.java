class Tree{
    List<Tree>child;
    String name;
    public Tree(String name,List<Tree>child){
        this.name=name;
        this.child=child;
    }
}
class ThroneInheritance {
    private Set<String>death;
    private Tree tree;
    private Map<String,Tree>addtoTree;
    public ThroneInheritance(String kingName) {
      death=new HashSet<>();  
      tree=new Tree(kingName,new ArrayList());
      addtoTree=new HashMap();
      addtoTree.put(kingName,tree);   
    }
    
    public void birth(String parentName, String childName) {
           Tree tmp =addtoTree.get(parentName);
           Tree childtree=new Tree(childName,new ArrayList());
           tmp.child.add(childtree);
            addtoTree.put( childName,childtree); 
    }
    
    public void death(String name) {
        death.add(name);
    }
    
    public List<String> getInheritanceOrder() {
        List<String>ans=new ArrayList<>();
        preOreder(tree,ans,death);
        return ans;
    }
    
    void preOreder(Tree n,List<String>ans,Set<String>death){
        if(n==null)return;
        if(!death.contains(n.name))ans.add(n.name);
         for(Tree name:n.child){
            preOreder(name,ans,death);
        }
    }
}
