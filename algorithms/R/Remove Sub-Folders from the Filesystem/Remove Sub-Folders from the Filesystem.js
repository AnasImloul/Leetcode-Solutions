var removeSubfolders = function(folder) {
    folder = folder.sort()
    const result = [];
    for(let i in folder){
        const f = folder[i];
        if(result.length == 0 || !f.startsWith(result[result.length -1] + "/"))
            result.push(f);
    }
    return result;
};
