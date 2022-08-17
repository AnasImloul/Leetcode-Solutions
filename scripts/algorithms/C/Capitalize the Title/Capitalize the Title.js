var capitalizeTitle = function(title) {
    const words = title.toLowerCase().split(' ');
    
    for (let i = 0; i < words.length; i++) {
        if (words[i].length > 2) {
            words[i] = words[i][0].toUpperCase() + words[i].slice(1);
        }
    }
    
    return words.join(' ');
};
