// Runtime: 457 ms (Top 37.59%) | Memory: 71.1 MB (Top 76.60%)
var findingUsersActiveMinutes = function(logs, k) {
    const map = new Map();

    for (const [userID, minute] of logs) {
        if (!map.has(userID)) map.set(userID, new Set());
        map.get(userID).add(minute);
    }

    const count = new Array(k).fill(0);

    for (const actions of map.values()) {
        count[actions.size - 1]++;
    }

    return count;
};