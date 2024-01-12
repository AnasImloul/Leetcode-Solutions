// Runtime: 83 ms (Top 88.06%) | Memory: 75.50 MB (Top 67.16%)

class Solution {
    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing, int[] start, int k) {
        int low = pricing[0];
        int high = pricing[1];
        int n = grid.length;
        int m = grid[0].length;
        Queue<Pair> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];
        ArrayList<Pair> list = new ArrayList<>();
        int dis = 0;
        q.add(new Pair(start[0], start[1], grid[start[0]][start[1]], 0));
        visited[start[0]][start[1]] = true;
		// normal bfs starts here.
        while (!q.isEmpty()) {
            int size = q.size();
            dis++;
            while (size-- > 0) {
                Pair p = q.remove();
                int x = p.x;
                int y = p.y;
                int val = p.val;
				// if nearby cells in range add that element to queue and mark the cell as visited.
                if (isInRange(x + 1, y, n, m, grid, visited, low, high)) {
                    q.add(new Pair(x + 1, y, grid[x + 1][y], dis));
                    visited[x + 1][y] = true;
                }
                if (isInRange(x - 1, y, n, m, grid, visited, low, high)) {
                    q.add(new Pair(x - 1, y, grid[x - 1][y], dis));
                    visited[x - 1][y] = true;
                }
                if (isInRange(x, y + 1, n, m, grid, visited, low, high)) {
                    q.add(new Pair(x, y + 1, grid[x][y + 1], dis));
                    visited[x][y + 1] = true;
                }
                if (isInRange(x, y - 1, n, m, grid, visited, low, high)) {
                    q.add(new Pair(x, y - 1, grid[x][y - 1], dis));
                    visited[x][y - 1] = true;
                }
				// add every element of queue to list.
                list.add(new Pair(p.x, p.y, p.val, p.dis));
            }
        }
        ArrayList<Pair> list2 = new ArrayList<>();
        for(Pair p: list) {
		    // remove the values from list if they are not in pricing range and add that to list2.
            if (p.val != 1 && p.val >= low && p.val <= high) {
                list2.add(new Pair(p.x, p.y, p.val, p.dis));
            }
        }
		// Most important part. Sorting the list2 on basis of the conditions given in question. Higher rank cells must be added first(before) in the list.
        Collections.sort(list2, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
			    // first check on basis of distance (high value, then add it before the second pair).
                if (p1.dis > p2.dis) {
                    return 1;
                } else if (p1.dis < p2.dis) {
                    return -1;
                } else {
				   // if distances are equal, then second check on basis of value (high value, then add it before the second pair).
                    if (p1.val > p2.val) {
                        return 1;
                    } else if (p1.val < p2.val) {
                        return -1;
                    } else {
					    // if distances and values are equal, then third check on basis of x-coordinate (high value, then add it before the second pair).
                        if (p1.x > p2.x) {
                            return 1;
                        } else if (p1.x < p2.x) {
                            return -1;
                        } else {
						   // if distances, values and x-coordinate are equal, then fourth check on basis of y-coordinate (high value, then add it before the second pair).).
                            if (p1.y > p2.y) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            }
        });
        List<List<Integer>> ans = new ArrayList<>();
		// selecting only first k values from list2, and adding there x,y - coordinates in ans arraylist.
        for(Pair p: list2) {
            if (k == 0) {
                break;
            } 
            k--;
            List<Integer> temp = new ArrayList<>();
            temp.add(p.x);
            temp.add(p.y);
            ans.add(new ArrayList<>(temp));
        }
        return ans;
    }
    
	// check whether i, j is in range or not (ignore visited cells and cells with zero value)
    private boolean isInRange(int i, int j, int n, int m, int[][] grid, boolean[][] visited, int low, int high) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return false;
        }
        return true;
    }
}

// Pair class for x-coordinate, y-coordinate, grid value, distance from start point
class Pair {
    int x; int y; int val; int dis;
    
    public Pair(int x, int y, int val, int dis) {
        this.x = x;
        this.y = y;
        this.val = val;
        this.dis = dis;
    }
}
