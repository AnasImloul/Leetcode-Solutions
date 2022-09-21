// Runtime: 1319 ms (Top 62.50%) | Memory: 51.1 MB (Top 87.50%)
/*
DSU Class Template
*/
class DSU {
    constructor() {
        this.parents = new Map();
        this.rank = new Map();
    }

    add(x) {
        this.parents.set(x, x);
        this.rank.set(x, 0);
    }

    find(x) {
        const parent = this.parents.get(x);
        if (parent === x) return x;
        const setParent = this.find(parent);
        this.parents.set(x, setParent);
        return setParent;
    }

    union(x, y) {
        const xParent = this.find(x), yParent = this.find(y);
        const xRank = this.rank.get(xParent), yRank = this.rank.get(yParent);
        if (xParent === yParent) return;
        if (xRank > yRank) {
            this.parents.set(yParent, xParent);
        } else if (yRank > xRank) {
            this.parents.set(xParent, yParent);
        } else {
            this.parents.set(xParent, yParent);
            this.rank.set(yParent, yRank + 1);
        }
    }
}

/*
Friend Requests
*/
var friendRequests = function(n, restrictions, requests) {
    const dsu = new DSU(), result = [];
    for (let i = 0; i < n; i++) dsu.add(i);

    for (let [friend1, friend2] of requests) {
        const parent1 = dsu.find(friend1), parent2 = dsu.find(friend2);
        let friendshipPossible = true;
        for (let [enemy1, enemy2] of restrictions) {
            const enemyParent1 = dsu.find(enemy1), enemyParent2 = dsu.find(enemy2);
            const condition1 = (enemyParent1 === parent1 && enemyParent2 === parent2);
            const condition2 = (enemyParent1 === parent2 && enemyParent2 === parent1);
            if (condition1 || condition2) {
                friendshipPossible = false;
                break;
            }
        }
        if (friendshipPossible) dsu.union(friend1, friend2);
        result.push(friendshipPossible);
    }
    return result;
};