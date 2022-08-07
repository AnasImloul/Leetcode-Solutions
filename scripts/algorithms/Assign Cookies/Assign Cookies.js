var findContentChildren = function(g, s) {
	g.sort(function(a, b) {
		return b - a;
	});
	s.sort(function(a, b) {
		return a - b;
	});
	
    let content = 0;
    for (let curG of g) {
        for (let curS of s) {
            if (curS >= curG) {
                s.pop();
				content++;	
			    break;
            }
        }
    }

	return content;
}
