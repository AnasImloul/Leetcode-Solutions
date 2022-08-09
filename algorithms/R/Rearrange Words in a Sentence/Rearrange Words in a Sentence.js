var arrangeWords = function(text) {
    let sorted = text.toLowerCase().split(' ');
    
    sorted.sort((a, b) => a.length - b.length);
    
    sorted[0] = sorted[0].charAt(0).toUpperCase() + sorted[0].slice(1);
    
    return sorted.join(' ');
};
