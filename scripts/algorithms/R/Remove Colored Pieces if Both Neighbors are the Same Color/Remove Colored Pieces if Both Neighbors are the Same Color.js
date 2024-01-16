// Runtime: 66 ms (Top 82.26%) | Memory: 45.70 MB (Top 32.26%)

/**
 * @param {string} colors
 * @return {boolean}
 */
var winnerOfGame = function(colors) {
        let alice_plays = 0, bob_plays = 0, count = 0;
        
        for (let i = 1; i < colors.length; i++) {
            if (colors[i] == colors[i - 1]) {
                count++;
            } else {
                if (colors[i - 1] == 'A') {
                    alice_plays += Math.max(0, count - 1);
                } else {
                    bob_plays += Math.max(0, count - 1);
                }
                count = 0;
            }
        }

        if (colors.charAt(colors.length - 1) == 'A') {
            alice_plays += Math.max(0, count - 1);
        } else {
            bob_plays += Math.max(0, count - 1);
        }
        
        return alice_plays > bob_plays;
    }
