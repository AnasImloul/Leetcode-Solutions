// Runtime: 8 ms (Top 86.11%) | Memory: 41.5 MB (Top 82.95%)
class Solution {
    public int racecar(int target) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 1, 0});
        Set<String> visited = new HashSet<>();

        while(!queue.isEmpty()){
            int[] item = queue.poll();
            int currPos = item[0];
            int currSpeed = item[1];
            int distance = item[2];

            if(currPos == target)
                return distance;

            // Choosing A
            int nextPos = currPos + currSpeed;
            int nextSpeed = currSpeed * 2;
            String posSpeed = new StringBuilder().append(nextPos).append(",").append(nextSpeed).toString();

            // If the particular state (position & speed) is not encountered earlier then we explore that state
            // And we also check if the nextPos is not beyond twice the size of target, then there is no point in exploring that route
            if(!visited.contains(posSpeed) && Math.abs(nextPos) < 2 * target){
                visited.add(posSpeed);
                queue.add(new int[]{nextPos, nextSpeed, distance + 1});
            }

            // Choosing R
            // We go in reverse only when we are moving away from the target in the positive or in the negative direction
            if((currPos + currSpeed > target && currSpeed > 0) || (currPos + currSpeed < target && currSpeed < 0)) {
                nextSpeed = currSpeed > 0 ? -1 : 1;
                posSpeed = new StringBuilder().append(currPos).append(",").append(nextSpeed).toString();

                if(!visited.contains(posSpeed) && Math.abs(currPos) < 2 * target){
                    visited.add(posSpeed);
                    queue.add(new int[]{currPos, nextSpeed, distance + 1});
                }
            }
        }
        return -1;
    }
}