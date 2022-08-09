class Solution {
    public int flipLights(int n, int presses) {
        //1, 2 -> 3
        //1, 3 -> 2
        //2, 3 -> 1
        //all on, all off, even on, odd on, 3k+1 on, 3k+0+2 on, 3k+1 w/ 2, 3k+1 w/ 3
        if (n == 2 && presses == 1) return 3;
        if (presses == 1) return Math.min(1 << Math.min(4, n), 4); //i chose 4 arbitarily, just has to be big enough to cover small number and less than 31
        if (presses == 2) return Math.min(1 << Math.min(4, n), 7);
        if (presses >= 3) return Math.min(1 << Math.min(4, n), 8);
        return 1;
    }
}
