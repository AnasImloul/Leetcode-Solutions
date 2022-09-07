// Runtime: 22 ms (Top 6.85%) | Memory: 49 MB (Top 11.86%)
/*
0. Start iterating over the asteroid one by one.
1. If the stack is not empty, and its top > 0 (right moving asteroid) and current asteroid < 0 (left moving), we have collision.
2. Pop all the smaller sized right moving asteroids (i.e. values > 0 but lesser than absolute value of left moving asteroid i.e. abs(<0))
3. Now that we have taken care of collisions with smaller size right moving asteroids, we need to see if there's a same sized right moving asteroid. If yes, just remove that one as well. Do not add the current left moving asteroid to the stack as it will be annihilated by the same sized right moving asteroid. Continue to the next iteration, we are done handling with this left moving asteroid.
4. If we are here, we still need to deal with the current left moving asteroid. Check the top of the stack as to what is there on top. If its a larger sized right moving asteroid, it will annihilate this current left moving asteroid. So Continue to the next iteration, we are done handling with this left moving asteroid.
5. If we are here, it means the current asteroid has survived till now either because it did not meet any collisions or won in the collisions. In this case, push the asteroid on to the stack.
6. Convert the stack to an array in return it.

*/
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        //0. Start iterating over the asteroid one by one.
        for(int a : asteroids) {

            //1. If the stack is not empty, and its top > 0 (right moving asteroid) and current asteroid < 0 (left moving), we have collision.
            //2. Pop all the smaller sized right moving asteroids (i.e. values > 0 but lesser than absolute value of left moving asteroid i.e. abs(<0))
            while(!stack.isEmpty() && stack.peek() > 0 && a < 0 && stack.peek() < Math.abs(a)) {
                stack.pop();
            }

            //3. Now that we have taken care of collisions with smaller size right moving asteroids, we need to see if there's a same sized right moving asteroid. If yes, just remove that one as well. Do not add the current left moving asteroid to the stack as it will be annihilated by the same sized right moving asteroid. Continue to the next iteration, we are done handling with this left moving asteroid.
            if(!stack.isEmpty() && stack.peek() > 0 && a < 0 && stack.peek() == Math.abs(a)) {
                stack.pop();
                continue;
            }

            //4. If we are here, we still need to deal with the current left moving asteroid. Check the top of the stack as to what is there on top. If its a larger sized right moving asteroid, it will annihilate this current left moving asteroid. So Continue to the next iteration, we are done handling with this left moving asteroid.
            if(!stack.isEmpty() && stack.peek() > 0 && a < 0 && stack.peek() > Math.abs(a)) {
                continue;
            }

            //5. If we are here, it means the current asteroid has survived till now either because it did not meet any collisions or won in the collisions. In this case, push the asteroid on to the stack.
            stack.push(a);

        }

        //6. Convert the stack to an array in return it.
        int[] ans = new int[stack.size()];
        int i = stack.size() - 1;
        while(!stack.isEmpty()) {
            ans[i] = stack.pop();
            i--;
        }
        return ans;
    }
}