// Runtime: 7 ms (Top 58.3%) | Memory: 43.50 MB (Top 67.5%)

class Solution {
    //what if we have changed the dice number, or changing the starting index or changing the ending index
    //so i have covered all possible ways in which this question can be asked

//bfs tip:- for better bfs, we can use marking first and then inserting it in the queue which works faster then removing first and then checking
    public int [] getans(int dice,HashMap<Integer,Integer> map,int si,int ei){
        //if si==ei just directly return 
        if(si==ei) return new int [] {0,0,0};
        LinkedList<int[]> que = new LinkedList<>();
        que.addLast(new int[] {si,0,0});
        int level = 0;
        //to stop visiting cells again
        boolean [] vis = new boolean [ei+1];
        vis[si]=true;
        //starting bfs
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int [] rem = que.removeFirst();
                int idx= rem[0];
                int lad = rem[1];
                int sna = rem[2];
                for(int i=1;i<=dice;i++){
                    int x =i+rem[0]; //checking all the steps
                    if(x<=ei){ //valid points
                        if(map.containsKey(x)){ //this means that we have encountered a snake or a ladder
                            if(map.containsKey(x)){
                                int val = map.get(x); 
                                if(val==ei) return new int[] {level+1,lad+1,sna};
                                if(!vis[val]){
                                    vis[val]=true;
                                    //if val>x this means we have a ladder and if less, then it is a snake
                                    que.addLast(val>x? new int [] {val,lad+1,sna}:new int [] {val,lad,sna+1});
                                }
                            }
                        }
                        else{
                            //if it is not present in map, then it is a normal cell, so just insert it directly
                            if(x==ei) return new int [] {level+1,lad,sna};
                            if(!vis[x]){
                                vis[x]=true;
                                que.addLast(new int [] {x,lad,sna});
                            }
                        }
                    }
                }
            }
            level++;
        }
        return new int [] {-1,0,0};
    }
    public int snakesAndLadders(int[][] board) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int count = 1;
        int n = board.length;
        boolean flag = true;
        //traversing the board in the board game fashion and checking if the count that is representing the cell number, if we encounter something other then -1, then it can be a snake or it can be a ladder and mapping that cell index (i.e count to that number)
        for(int i=n-1;i>=0;i--){
            //traversing in the order of the board
            if(flag){
                for(int j=0;j<n;j++){
                    if(board[i][j]!=-1){
                        map.put(count,board[i][j]);   
                    }
                    count++;
                    flag=false;
                }
            }
            else{
                //reversing the direction
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]!=-1){
                        map.put(count,board[i][j]);
                    }
                    flag=true;
                    count++;
                }
            }
        }
        //if snake on destination then just return -1;
        if(board[0][0]!=-1) return -1;
        //we only want the minimum steps, but for more conceptual approach for this question, {minm steps,ladders used, snakes used} 
        int [] ans = getans(6,map,1,n*n);;
        return ans[0];
        
    }
}