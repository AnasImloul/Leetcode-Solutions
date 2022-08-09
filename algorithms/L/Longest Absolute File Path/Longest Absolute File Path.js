function isFile(path) {
    return path.includes('.')
}

var lengthLongestPath = function(input) {
    const segments = input.split('\n');
    
    let max = 0;
    let path = [];
    for (const segment of segments) {
        if (segment.startsWith('\t')) {
            const nesting = segment.match(/\t/g).length;
            
            while (nesting < path.length) {
                path.pop();
            }
            
            path.push(segment.replace(/\t/g, ''))
        } else {
            path = [segment]
        }
        
        if (isFile(path.at(-1))) {
            const filePath = path.join('/');
            if (filePath.length > max) {
                max = filePath.length;
            }
        }
    }
    
    return max;
};
