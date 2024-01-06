// Runtime: 211 ms (Top 100.0%) | Memory: 57.90 MB (Top 100.0%)

var maxTaskAssign = function(tasks, workers, pills, strength) {
    workers.sort((b, a) => b - a);
    tasks.sort((b, a) => b - a);

    let lTasks = -1, rTasks = Math.min(tasks.length, workers.length) - 1;

    while (lTasks < rTasks) {
        const midTasks = (lTasks + rTasks + 1) >> 1;
        let t = midTasks;

        for (let w = workers.length - 1, freePills = pills, queue = []; t >= 0; t--) {
            if (queue[0] >= tasks[t]) {
                queue.shift();
            } else if (workers[w] >= tasks[t]) {
                w--;
            } else if (freePills > 0) {
                while (w >= 0 && workers[w] + strength >= tasks[t])
                    queue.push(workers[w--]);

                if (queue.length == 0) break;
                queue.pop(), freePills--;
            } else break;
        }
        t == -1 ? lTasks = midTasks : rTasks = midTasks - 1;
    }
    return lTasks + 1;
};
