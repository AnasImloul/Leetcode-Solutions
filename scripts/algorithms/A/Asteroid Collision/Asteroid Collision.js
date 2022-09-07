// Runtime: 120 ms (Top 34.05%) | Memory: 44.1 MB (Top 63.23%)
/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {

    const s = [];
    for (let i = 0; i < asteroids.length; i++) {
        const a = asteroids[i];

        // Negative asteroids to the left of the stack can be ignored.
        // They'll never collide. Let's just add it to the answer stack and
        // move on. I consider this a special case.
        if ((s.length === 0 || s[s.length -1] < 0) && a < 0 ) {
            s.push(a);

        // If an asteroid a is positive (l to r), it may still collide with an
        // a negative asteroid further on in the asteroids array
        } else if (a > 0) {
            s.push(a);

        // a is negative. It can only collide with positive ones in
        // the stack. The following will keep on iterating
        // until it is dealt with.
        } else {
            const pop = s.pop();

            // positive pop beats negative a, so pick up pop
            // and re-add it to the stack.
            if (Math.abs(pop) > Math.abs(a)) {
                s.push(pop);

            // a has larger size than pop, so pop will get dropped
            // and we'll retry another iteration with the same
            // negative a asteroid and whatever the stack's state is.
            } else if (Math.abs(pop) < Math.abs(a)) {
                i--;
            // magnitude of positive pop and negative a are the same
            // so we can drop both of them.
            } else {
                continue;
            }
        }
    }

    // The stack should be the answer
    return s;

};