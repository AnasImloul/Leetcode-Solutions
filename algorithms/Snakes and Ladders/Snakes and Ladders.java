class Solution {
    public int snakesAndLadders(int[][] board) {
        if(board == null || board.length == 0) return 0; //Empty Input
        int n = board.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        getSnakesAndLadders(board , map); //this function will get snake&ladder positions in grid
        
        int target = n*n;
        boolean[] visited = new boolean[target + 1]; //assumeing 1based index so +1;
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        queue.add(1);
        visited[1] = true;
        
        int steps = 0;
        while(queue.isEmpty() == false){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                int current = queue.poll();
                if(current == target){
                    return steps;
                }
                //go for all possiblities
                for(int dice = 1; dice <= 6; dice++){
                    int jump = current + dice;
                    if(jump > target){
                        break;
                    }
                    //if this ladder or snake already used then don't use again
                    if(map.containsKey(jump) && visited[map.get(jump)]) continue;
                    
                    //if there is ladder on place which not used already
                    if(map.containsKey(jump) && visited[map.get(jump)] == false){
                        visited[jump] = true; //start of ladder
                        queue.add(map.get(jump));
                        visited[map.get(jump)] = true; //end of ladder
                    }else if(visited[jump] == false){
                        queue.add(jump);
                        visited[jump] = true;
                    }
                }
            }
            steps += 1;
        }
        return -1;
    }
    
    //function to traverse spiraly and get all snake&ladder positions
    public void getSnakesAndLadders(int[][] board , HashMap<Integer,Integer> map){
        int startRow = 0;
        int position = 1;
        for(int row = board.length-1; row >= 0; row--){
            if(startRow%2 == 0){
                for(int col = 0; col < board.length; col++){
                    if(board[row][col] != -1){
                        int dest = board[row][col];
                        map.put(position , dest);
                    }
                    position += 1;
                }
            }else{
                for(int col = board.length-1; col >= 0; col--){
                    if(board[row][col] != -1){
                        int dest = board[row][col];
                        map.put(position, dest);
                    }
                    position += 1;
                }
            }
            startRow += 1;
        }
    }
}

