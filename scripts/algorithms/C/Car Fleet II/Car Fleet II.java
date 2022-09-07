// Runtime: 40 ms (Top 65.78%) | Memory: 229.1 MB (Top 68.82%)
class Solution {
    public double[] getCollisionTimes(int[][] cars) {
        int n = cars.length;
        double[] res = new double[n];
        Arrays.fill(res, -1.0);

        // as soon as a car c1 catches another car c2, we can say c1 vanishes into c2; meaning that
        // after catching c2, we may view c1 as non-existing (cars before c1 may not catches c1);

        /** Define a stack storing the index of cars as follows:

        Assuming cars c_0, c_1, c_2, ... , c_k are in the stack, they satisfy:
            1. v0 > v1 > v2 ... > vk where v_i is the velocity of car c_i
            2. c_(i+1) is the car that c_i vanishes into

        Namely, if only these cars exist, then what will happened is that c_0 vanishes into c_1,
        then c_1 vanishes into c_2, ..., c_(k-1) vanishes into c_k;
        */
        Deque<Integer> stack = new LinkedList<>();
        for (int i = n-1; i >= 0; i--) {
            int[] c1 = cars[i];
            while (!stack.isEmpty()) {
                int j = stack.peekLast();
                int[] c2 = cars[j];

                /** If both conditions are satisfied:
                    1. c1 is faster than c2
                    2. c1 catches c2 before c2 vanishes into other car

                Then we know that c2 is the car that c1 catches first (i.e., c1 vanishes into c2)
                    ==> get the result for c1

                Note neither c1 nor c2 is polled out from the stack considering the rule of stack.
                */

                if (c1[1] > c2[1] && (res[j] == -1.0 || catchTime(cars, i, j) <= res[j])) {
                    res[i] = catchTime(cars, i, j);
                    break;
                }

                /** Now we have either one of situations
                    1. c1 is slower than c2
                    2. c1 potentially catches c2 AFTER c2 vanishes

                    Claim: no car before c1 will vanish into c2

                    1. ==> cars before c1 will vanish into c1 first before catching c2
                    2. <==> c2 "vanishes" into another car even before c1 catches it

                Either way, c2 can not be catched by c1 or cars beofre c1 ==> poll it out from stack

                */
                stack.pollLast();
            }
            stack.offerLast(i);
        }
        return res;
    }

    // time for cars[i] to catch cars[j]
    private double catchTime(int[][] cars, int i, int j) {
        int dist = cars[j][0] - cars[i][0];
        int v = cars[i][1] - cars[j][1];

        return (double)dist / v;
    }
}