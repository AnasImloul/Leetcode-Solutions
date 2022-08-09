class Trie{
    constructor(){
        this.T=[-1,-1]
    }
    insert(val){
        let cur=this.T,firstchangeNode=null,fcIndex=null
        for(let i=17;i>=0;i--){ // a node can be up to (1e5), whose log2 is 17, so at most we need 17 bits
            let next=Number(Boolean(val&(1<<i)))
            if(cur[next]===-1){
                if(firstchangeNode===null)
                    firstchangeNode=cur,fcIndex=next
                cur[next]=[-1,-1]
            }
            cur=cur[next]
        }
        // memorize the first change (if any) that was made during the insertion of val
        return [firstchangeNode,fcIndex] 
    }
    search(val){
        let cur=this.T,res=0
        for(let i=17;i>=0;i--){
            let xor= 1^Number(Boolean(val&(1<<i)))
            if(cur[xor]!==-1)
                cur=cur[xor],res|=(1<<i)
            else
                cur=cur[xor^1]
        }
        return res
    }
}
var maxGeneticDifference = function(parents, queries) {
    let root,n=parents.length,res=[...Array(n)].map(d=>{}),
        Q=[...Array(n)].map(d=>[]),adj=[...Array(n)].map(d=>[])
    // create some objects for fast access to the results
    for(let [node,val] of queries)
        Q[node].push(val),
        res[node]={},res[node][val]=undefined
    // create an adjacency list that points to the next node 
    for(let i=0;i<parents.length;i++)
        if(parents[i]!==-1)
            adj[parents[i]].push(i)
        else 
            root=i
    let T=new Trie()
    //traverse the tree
    let dfs=(node)=>{
        let [fnode,index]=T.insert(node) //insert the value of a node to our trie
        for(let q of Q[node]) //answer all the queries for our current node
            res[node][q]=T.search(q) 
        for(let nei of adj[node]) // dfs to the children nodes
            dfs(nei)
        if(fnode!==null) // if my trie was altered during this turn, revert the change
            fnode[index]=-1
    }
    dfs(root)
    //return the results, which have already been calculated 
    return queries.map( ([node,val])=>res[node][val])
};
