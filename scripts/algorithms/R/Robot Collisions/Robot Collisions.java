// Runtime: 50 ms (Top 58.02%) | Memory: 63.90 MB (Top 17.28%)

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        List<Robot> robots = new ArrayList();
        for(int i=0;i<positions.length;i++) {
            robots.add(new Robot(i, positions[i], healths[i], directions.charAt(i)));
        }
        Collections.sort(robots);
        List<Robot> survived = new ArrayList<>();
        Stack<Robot> stack = new Stack<>();
        for(Robot robot: robots) {
            if(robot.dir == 'R') {
                stack.push(robot);
                continue;
            }
            while(!stack.isEmpty() && robot.hlt > 0) {
                Robot peek = stack.peek();
                if(peek.hlt == robot.hlt) {
                    stack.pop();
                    robot.hlt = 0;
                } else if(peek.hlt > robot.hlt) {
                    robot.hlt = 0;
                    peek.hlt -= 1;
                } else {
                    stack.pop();
                    robot.hlt -= 1;
                }
            }
            if(robot.hlt > 0) survived.add(robot);
        }
        while(!stack.isEmpty()) {
            survived.add(stack.pop());
        }
        Collections.sort(survived, (o1, o2) -> o1.idx - o2.idx);
        return survived.stream().map(robot -> robot.hlt).collect(Collectors.toList());
    }
}

class Robot implements Comparable<Robot> {
    public int idx;
    public int pos;
    public int hlt;
    public char dir;
    
    public Robot(int i, int p, int h, char d) {
        idx = i;
        pos = p;
        hlt = h;
        dir = d;
    }
    
    @Override
    public int compareTo(Robot robot) {
        return this.pos - robot.pos;
    }
}
