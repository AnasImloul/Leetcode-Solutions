var taskSchedulerII = function(tasks, space) {
    let days = 0, readyFor = {};
    
    tasks.forEach(task => {
        days = Math.max(days + 1, readyFor[task] ?? 0);
        readyFor[task] = days + space + 1;
    })
    
    return days;
};
