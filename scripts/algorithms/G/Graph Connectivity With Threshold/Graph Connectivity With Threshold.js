// Runtime: 291 ms (Top 33.33%) | Memory: 62.6 MB (Top 100.00%)
var areConnected = function(n, threshold, queries) {

    // if(gcd(a,b)>threshold), a and b are connected

    // 2 is connected with : 2, 4,6,8,10,12,14,16, (gcd(2,y)=2)
    // 3 is connected with : 3,6,9,12,... (gcd(3,y)=3)
    // 4 is connected with : 4,8,12,16,20,24,28, (gcd(4,y)=4)
    // 6 is connected with : 6,12,18...,cos (gcd(6,y)=6)
    // 5 is connected with : 10,15,20,25,...n cos (gcd(5,y)=6)
    // etc

    let dsu=new UnionFind(n+1) //to map n=>n (no node 0 on my question)

    for (let node = threshold+1; node <=n; node++) //basically this ensures that the road exists
        //cos gcd(node,secondnode)==node >threshold
        for (let secondnode = node+node; secondnode <=n; secondnode+=node)
            dsu.union(node,secondnode)

    return queries.map(([a,b])=>dsu.sameGroup(a,b))
};
class UnionFind {

    constructor(size){
        //the total count of different elements(not groups) in this union find
        this.count=size
        //tracks the sizes of each of the components(groups/sets)
        //groupsize[a] returns how many elements the component with root a has
        this.groupSize=[...Array(size)]
        //number of components(groups) in the union find
        this.numComponents=size
        //points to the parent of i, if parent[i]=i, i is a root node
        this.parent=[...Array(size)] //which is also the index of the group

        //put every element into its own group
        // rooted at itself
        for (let i = 0; i < size; i++) {
            this.groupSize[i]=i
            this.parent[i]=i
        }
    }

    //returns to which component (group) my element belongs to
    // (n) --Amortized constant time
    // Update: Also compresses the paths so that each child points to its
    // parent
    find(element){
        let root=element
        //find the parent of the group the elemnt belongs to
        // When root===parent[root] is always the parent of that group (root)
        while(root!=this.parent[root])
            root=this.parent[root]

        // Compression, point the element to its parent if its not already pointed
        // Tldr: Not only do I point my element to its actual root, i point any
        // inbetween elements to that root aswell
        while(element!=root){
            let next=this.parent[element]
            this.parent[element]=root
            element=next
        }

        return root
    }

    //Unifies the sets containing A and B
    // if not already unified
    // (n) --Amortized constant time
    union(A,B){
        let root1=this.find(A) //parent of A
            ,root2=this.find(B) //parent of B
        if(root1===root2) //already unified
            return
        // I want to put the set with fewer elements
        // to the one with more elemenets
        if(this.groupSize[root1]<this.groupSize[root2]){
            this.groupSize[root2]+=this.groupSize[root1]
            this.parent[root1]=this.parent[root2]
        }
        else {
            this.groupSize[root1]+=this.groupSize[root2]
            this.parent[root2]=this.parent[root1]
        }

        this.numComponents-- //cos 1 less group, since i merged 2
    }

    //same parent=>samegroup
    sameGroup=(A,B)=>this.find(A)==this.find(B)

    //essentially the groupSize of its parent's group
    sizeOfGroup=(A)=>this.groupSize[this.find(A)]

}