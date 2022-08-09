// Escape The Ghosts
// Leetcode: https://leetcode.com/problems/escape-the-ghosts/

class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int dist = Math.abs(target[0]) + Math.abs(target[1]);
        for (int[] ghost : ghosts) {
            if (Math.abs(ghost[0] - target[0]) + Math.abs(ghost[1] - target[1]) <= dist) {
                return false;
            }
        }
        return true;       
    }
}
