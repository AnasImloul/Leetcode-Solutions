class Node{
    constructor(val,parent){
        this.val=val,this.parent=parent,this.children={},this.hash
    }
}
class Trie{
    constructor(){
        this.root=new Node('')
        this.hashMemo={}
    }
    insert(path){
        let cur=this.root
        for(let node of path )
            if(cur.children[node]!==undefined)
                cur=cur.children[node]
            else
                cur.children[node]=new Node(node,cur),
                cur=cur.children[node]
    }
    traverse(node=this.root){
        node.hash=[]
        if(node.children)
            for(let child of Object.values(node.children))
                node.hash.push(this.traverse(child))
        node.hash=node.hash.join('~')
        if(node.hash!==''){
            if(this.hashMemo[node.hash]===undefined)
                this.hashMemo[node.hash]=[] 
            this.hashMemo[node.hash].push(node)
            return node.val+'/['+node.hash+']'
        }
        return node.val
    }
    delete(node=this.root){
        if(!node || node.hash===undefined)
            return
        else if(this.hashMemo[node.hash] && this.hashMemo[node.hash].length>1)
            for(let todelete of this.hashMemo[node.hash])
                delete todelete.parent.children[todelete.val]
        else
            for(let child of Object.values(node.children))
                this.delete(child)
    }
    serialize(node=this.root,stack=[],res=[]){
        if(node.val!=='')
            stack.push(node.val),
            res.push([...stack])
        for(let child of Object.values(node.children))
            this.serialize(child,stack,res)
        stack.pop()
        return res
    }
}

var deleteDuplicateFolder = function(paths) {
    let T=new Trie()
    for(let P of paths)
        T.insert(P)
    T.traverse()
    T.delete()
    return T.serialize()
};
