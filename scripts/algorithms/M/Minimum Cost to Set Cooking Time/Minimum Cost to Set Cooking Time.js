// Runtime: 105 ms (Top 40.54%) | Memory: 42.2 MB (Top 81.08%)
/**
 * @param {number} startAt
 * @param {number} moveCost
 * @param {number} pushCost
 * @param {number} targetSeconds
 * @return {number}
 */
var minCostSetTime = function(startAt, moveCost, pushCost, targetSeconds) {
    let cost = Infinity;

    let maxMinutes = Math.floor(targetSeconds / 60);

    for(let min = 0; min <= maxMinutes; min++) {
        let secs = targetSeconds - min * 60;

        if (secs > 99 || min > 99) continue;

        let buttons = String(100 * min + secs);
        let prev = Number(buttons[0]);

        let sum = 0;

        //start index will vary according to startAt pointer
        let start = 0;

        //If startAt is equal to first button, we need to add pushCost fatigue
        if(prev === startAt) {
            sum += pushCost;
            start = 1;
         } else {
            //Else we need to add moveCost fatigue
            sum += moveCost;
         }

        for(let i = start; i < buttons.length; i++) {
            let button = Number(buttons[i]);

            if(button !== prev) {
                sum += moveCost + pushCost;
            } else {
                sum += pushCost;
            }

            prev = button;
        }

        cost = Math.min(cost, sum)
    }

    return cost;
};