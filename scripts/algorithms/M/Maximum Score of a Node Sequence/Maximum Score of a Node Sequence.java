// Runtime: 25 ms (Top 99.80%) | Memory: 131.6 MB (Top 18.36%)
class Solution {
    public int maximumScore(int[] scores, int[][] edges) {
        int n = scores.length;

        int[][] count = new int[n][6];
        for (int[] edge : edges) {
            int s = edge[0];
            int e = edge[1];
            if (count[s][0] == 0) {
                count[s][1] = e;
                count[s][0] = scores[e];
            } else if (count[s][2] == 0) {
                if (scores[e] > count[s][0]) {
                    count[s][3] = count[s][1];
                    count[s][2] = count[s][0];
                    count[s][1] = e;
                    count[s][0] = scores[e];
                } else {
                    count[s][3] = e;
                    count[s][2] = scores[e];
                }
            } else if (scores[e] > count[s][4]) {
                if (scores[e] > count[s][0]) {
                    count[s][5] = count[s][3];
                    count[s][4] = count[s][2];
                    count[s][3] = count[s][1];
                    count[s][2] = count[s][0];
                    count[s][1] = e;
                    count[s][0] = scores[e];
                } else if (scores[e] > count[s][2]) {
                    count[s][5] = count[s][3];
                    count[s][4] = count[s][2];
                    count[s][3] = e;
                    count[s][2] = scores[e];
                } else {
                    count[s][5] = e;
                    count[s][4] = scores[e];
                }
            }
            if (count[e][0] == 0) {
                count[e][1] = s;
                count[e][0] = scores[s];
            } else if (count[e][2] == 0) {
                if (scores[s] > count[e][0]) {
                    count[e][3] = count[e][1];
                    count[e][2] = count[e][0];
                    count[e][1] = s;
                    count[e][0] = scores[s];
                } else {
                    count[e][3] = s;
                    count[e][2] = scores[s];
                }
            } else if (scores[s] > count[e][4]) {
                if (scores[s] > count[e][0]) {
                    count[e][5] = count[e][3];
                    count[e][4] = count[e][2];
                    count[e][3] = count[e][1];
                    count[e][2] = count[e][0];
                    count[e][1] = s;
                    count[e][0] = scores[s];
                } else if (scores[s] > count[e][2]) {
                    count[e][5] = count[e][3];
                    count[e][4] = count[e][2];
                    count[e][3] = s;
                    count[e][2] = scores[s];
                } else {
                    count[e][5] = s;
                    count[e][4] = scores[s];
                }
            }
        }
        int max = -1;
        for (int[] edge : edges) {
            int s = edge[0];
            int e = edge[1];
            int pos = scores[s] + scores[e];
            int p1 = -1;
            int p2 = -1;
            boolean fine = true;
            if (count[s][1] == e) {
                if (count[s][2] == 0)
                    fine = false;
                p1 = count[s][3];
                if (count[s][4] > 0)
                    p2 = count[s][5];
            } else if (count[s][3] == e) {
                if (count[s][0] == 0)
                    fine = false;
                p1 = count[s][1];
                if (count[s][4] > 0)
                    p2 = count[s][5];
            } else {
                p1 = count[s][1];
                if (count[s][0] == 0)
                    fine = false;
                if (count[s][2] > 0)
                    p2 = count[s][3];
            }
            int p3 = -1;
            int p4 = -1;
            if (count[e][1] == s) {
                if (count[e][2] == 0)
                    fine = false;
                p3 = count[e][3];
                if (count[e][4] > 0)
                    p4 = count[e][5];
            } else if (count[e][3] == s) {
                if (count[e][0] == 0)
                    fine = false;
                p3 = count[e][1];
                if (count[e][4] > 0)
                    p4 = count[e][5];
            } else {
                p3 = count[e][1];
                if (count[e][0] == 0)
                    fine = false;
                if (count[e][2] > 0)
                    p4 = count[e][3];
            }
            if (fine) {
                if (p1 == p3) {
                    if (p4 > -1)
                        max = Math.max(max, pos + scores[p1] + scores[p4]);
                    if (p2 > -1)
                        max = Math.max(max, pos + scores[p1] + scores[p2]);
                } else {
                    max = Math.max(max, pos + scores[p1] + scores[p3]);
                }
            }
        }
        return max;
    }
}