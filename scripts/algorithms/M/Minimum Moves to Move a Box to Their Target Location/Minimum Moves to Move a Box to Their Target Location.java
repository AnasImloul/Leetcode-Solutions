// Runtime: 51 ms (Top 51.89%) | Memory: 54.4 MB (Top 47.17%)
/**
  Finds Initial State (State consists of shopkeeper & box locations + # of boxMoves)
  Uses BFS/A* Algorithm to visit valid transition states
  Note: The min heuristic here is # of boxMoves + manHattanDistance between box & target locations
*/
class Solution {
    private int targetRow;
    private int targetCol;
    private char[][] grid;
    private static int[][] DIRS = {
            {1,0}, //Down
            {-1,0},//Up
            {0,1}, //Right
            {0,-1} //Left
    };

    /**
      State holds shopkeeper and box location, as well as how many times the box has been pushed
    */
    class State implements Comparable<State>{
        int personRow;
        int personCol;
        int boxRow;
        int boxCol;
        int boxPushes;

        public State(int personRow, int personCol, int boxRow, int boxCol, int boxPushes){
            this.personRow = personRow;
            this.personCol = personCol;
            this.boxRow = boxRow;
            this.boxCol = boxCol;
            this.boxPushes = boxPushes;
        }

        // Override equals - used along with hashcode when we have visited HashSet
        public boolean equals(Object o){
            State other = (State) o;
            return
            this.personRow == other.personRow &&
            this.personCol == other.personCol &&
            this.boxRow == other.boxRow &&
            this.boxCol == other.boxCol;
        }

        // Override the hashCode - Note: it's okay for this to have collisions
        // But it won't due to the problem constraint that there is a bound on NxM dimensions
        public int hashCode(){
            return personRow *10_000 + personCol * 1_000 + boxRow * 100 + boxCol;
        }

        // Override to string method - helpful in debugging state.
        public String toString(){
            return "ShopKeeper:{row:"+personRow+", col:"+personCol+"}" +
                   "Box:{row:"+boxRow+", col:"+boxCol+"}";
        }

        // Implement comparable interface such that we return the state that
        // has the possibility of lowest distance using box push count + Manhattan distance
        public int compareTo(State other){
            int minDistanceThis = this.boxPushes + distanceToTarget(this);
            int minDistanceOther = other.boxPushes + distanceToTarget(other);
            return Integer.compare(minDistanceThis, minDistanceOther);
        }

    }

    // Calculates Manhattan distance
    private int distanceToTarget(State state){
        int yDiff = Math.abs(state.boxCol - targetCol);
        int xDiff = Math.abs(state.boxRow - targetRow);
        return yDiff + xDiff;
    }

    /**
       Given a state, compare box location to target location to determine if it is
       a solution state.
    */
    private boolean isSolutionState(State state){
        return state.boxRow == targetRow && state.boxCol == targetCol;
    }

    /**
        Given a state, finds all valid transition states.
        This is accomplished by moving the ShopKeeper in all 4 directions and validate
        - Next ShopKeeper location is in bounds and is not a wall

        We have additional logic for when the next shopkeeper location is the box location:
        - Get next box location, by pushing the same direction, again validate that
          the next box location is in bounds, and is not a wall.

        If it's a valid transition, create the new state with the new shop keeper location
        and if the box moved, the new box location (also increment the number of box moves).

    **/
    private List<State> getNeighbors(State state){

        int personRow = state.personRow;
        int personCol = state.personCol;
        int boxRow = state.boxRow;
        int boxCol = state.boxCol;

        List<State> states = new ArrayList<>();
        for(int[] dir : DIRS){
            int rowMove = dir[0];
            int colMove = dir[1];
            int personRowNew = personRow + rowMove;
            int personColNew = personCol + colMove;
            // Shopkeeper cannot move into wall or go out of bounds skip to next direction
            if(!inBounds(personRowNew, personColNew) ||
               isWall(personRowNew, personColNew)){
                continue;
            }
            // Whether or not person will collide with box
            boolean willPushBox = personRowNew == boxRow && personColNew == boxCol;

            if(willPushBox){
                int boxRowNew = boxRow + rowMove;
                int boxColNew = boxCol + colMove;
                // Validate box can be pushed - if so push box and add to neighbor states
                if(inBounds(boxRowNew, boxColNew) &&
                   !isWall(boxRowNew, boxColNew)){
                   states.add(new State(personRowNew, personColNew, boxRowNew, boxColNew, state.boxPushes + 1));
                }
            } else {
                //Shop keeper moved, but not box
                states.add(new State(personRowNew, personColNew, boxRow, boxCol, state.boxPushes));
            }
        }
        return states;

    }

    // Given row/col, return whether it is wall
    private boolean isWall(int row, int col){
        char cell = grid[row][col];
        return cell == '#';
    }

    // Given row/col return whether is inBounds
    private boolean inBounds(int row, int col){
        int rows = grid.length;
        int cols = grid[0].length;
        if(row < 0 || col < 0 || row > rows-1 || col > cols-1){
            return false;
        }
        return true;
    }

    /**
      Returns initial state. Also finds and stores the target location.
    */
    private State getInitialState(){

        int shopKeeperRow=0;
        int shopKeeperCol=0;

        int boxRow = 0;
        int boxCol = 0;

        for(int r=0; r<grid.length; r++){
            char[] row = grid[r];
            for(int c=0; c<row.length; c++){
                char cell = grid[r][c];
                if(cell == 'T'){
                    this.targetRow = r;
                    this.targetCol = c;
                }
                else if(cell == 'B'){
                    boxRow = r;
                    boxCol = c;
                } else if(cell == 'S'){
                    shopKeeperRow = r;
                    shopKeeperCol = c;
                }
            }
        }

        return new State(shopKeeperRow, shopKeeperCol, boxRow, boxCol, 0);
    }

    public int minPushBox(char[][] grid) {
        this.grid = grid;

        State initialState = getInitialState();
        Queue<State> queue = new PriorityQueue<>();
        Set<State> visited = new HashSet<>();
        queue.offer(initialState);

        // Explore every state using BSF and keep track of the best solution
        while(!queue.isEmpty()){
            State state = queue.poll();
            if(visited.contains(state)){
                continue;
            }
            visited.add(state);
            /*
              Note: the reason we can return the first solution state we find, is because we are
              using priority queue with minDistance heuristic which means the first solution we find
              is guaranteed to be the optimal solution - (A* Algorithm)
            */
            if(isSolutionState(state)){
                return state.boxPushes;
            }
            for(State neighbor : getNeighbors(state)){
                if(!visited.contains(neighbor)){
                    queue.offer(neighbor);
                }
            };
        }
        // No solution - return -1
        return -1;
    }

}