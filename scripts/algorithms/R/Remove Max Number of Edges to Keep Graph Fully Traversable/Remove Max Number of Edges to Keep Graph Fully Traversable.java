// Runtime: 29 ms (Top 44.9%) | Memory: 82.52 MB (Top 97.7%)

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) 
    {
        Arrays.sort(edges, (a, b)->{
            return b[0]-a[0];
        });//giving the priority to third type of edge or the edge which Bob and Alice both can access
        
        //1-based indexing of nodes 
        int []parentAlice= new int[n+1];//Graph 1 for Alice connectedness
        int []parentBob= new int[n+1];//Graph 2 for Bob connectedness
        
        for(int i= 0; i< n+1; i++){//every node is pointing to itself, at first no connection is considered all sets are independent(no dependency) 
            parentAlice[i]= i;
            parentBob[i]= i;
        }
        
        //number of merged unique node for Alice and Bob that are required to maintain the connectedness of Alice and Bob graph nodes//intialised with one because merging happens in pair 
        int mergeAlice= 1;
        int mergeBob= 1;
        
        //number of cyclic or the non dependent node, that are not required for the connectedness of Alice and Bob nodes  
        int removeEdge= 0;
        
        for(int []edge: edges)
        {
            int cat= edge[0];//category of edge 1)edge Alice can only access 2)edge Bob can only access 3)edge both Alice and Bob can access
            int u= edge[1];
            int v= edge[2];
            
            if(cat == 3){//edge both Alice and Bob an access
                
                //creating dependency of nodes in graph 1 and 2 
                boolean tempAlice= union(u, v, parentAlice);
                boolean tempBob= union(u, v, parentBob);
                
                if(tempAlice == true)
                    mergeAlice+= 1;
                
                if(tempBob == true)
                    mergeBob+= 1;
                
                if(tempAlice == false && tempBob == false)//retundant or the cyclic non-dependent edge//both Alice and Bob don't rquire it connection is already there between these pair of nodes
                    removeEdge+= 1;
            }
            else if(cat == 2){//edge Bob can only access 
                
                //creating dependency of nodes in graph 2
                boolean tempBob= union(u, v, parentBob);
                
                if(tempBob == true)
                    mergeBob+= 1;
                else//no merging of set is done, that means that this edge is not required because it will form cycle or the dependency 
                    removeEdge+= 1;
            }
            else{//edge Alice can only access 
                
                //creating dependency of nodes in graph 1
                boolean tempAlice= union(u, v, parentAlice);
                
                if(tempAlice == true)
                    mergeAlice+= 1; 
                else//no merging of set is done, that means that this edge is not required because it will form cycle or the dependency 
                    removeEdge+= 1;
            }
        }
        if(mergeAlice != n || mergeBob != n)//all node are not connected, connectedness is not maintained 
            return -1;
        return removeEdge;//number of edge removed by maintaining the connectedness 
    }
    
    public int find(int x, int[] parent)
    {
        if(parent[x] == x)//when we found the absolute root or the leader of the set 
            return x;
        
        int temp= find(parent[x], parent);
        
        parent[x]= temp;//Path Compression//child pointing to the absolute root or the leader of the set, while backtracking
        
        return temp;//returning the absolute root 
    }
    
    public boolean union(int x, int y, int[] parent)
    {
        int lx= find(x, parent);//leader of set x or the absolute root
        int ly= find(y, parent);//leader of set y or the absolute root
        
        if(lx != ly){//belong to different set merging 
            
            //Rank Compression is not done, but you can do it 
            parent[lx]= ly;
            
            return true;//union done, dependency created
        }
        else
            return false;//no union done cycle is due to this edge 
    }//Please do Upvote, it helps a lot 
}