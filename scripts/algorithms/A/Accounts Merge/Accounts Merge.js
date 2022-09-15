// Runtime: 280 ms (Top 40.08%) | Memory: 78.1 MB (Top 13.99%)
/**
 * @param {string[][]} accounts
 * @return {string[][]}
 */

var accountsMerge = function(accounts) {

    let graph = {};
    let nameDict = {};

    for (let acc of accounts) {
        let name = acc[0];
        nameDict[acc[1]] = name;
        for (let i=1;i<acc.length;i++) {
            if (!graph[acc[i]]) graph[acc[i]] = new Set();
            nameDict[acc[i]] = name;
            if (i != 1) {
                graph[acc[1]].add(acc[i]);
                graph[acc[i]].add(acc[1]);
            }
        }
    }

    let res = [];
    let visited = new Set();

    let dfs = function (key) {
        visited.add(key);
        let emails = [key];
        graph[key].forEach((e)=>{
            if (!visited.has(e)) {
                emails.push(...dfs(e));
            }
        })

        return emails;
    }

    for (let key in graph) {
        if (!visited.has(key)) {
            let temp = dfs(key);
            temp.sort();
            temp.unshift(nameDict[temp[0]]);
            res.push(temp);
        }
    }

    return res;
};