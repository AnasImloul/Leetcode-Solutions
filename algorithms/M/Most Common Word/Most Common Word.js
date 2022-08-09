// Runtime: 69 ms, faster than 94.32%
// Memory Usage: 44.2 MB, less than 61.20%
var mostCommonWord = function(paragraph, banned) {
	paragraph = new Map(Object.entries(
	paragraph
		.toLowerCase()
		.match(/\b[a-z]+\b/gi)
		.reduce((acc, cur) => ((acc[cur] = (acc[cur] || 0) + 1), acc), {}))
		.sort((a, b) => b[1] - a[1])
	);
	for (let i = 0; i < banned.length; i++) paragraph.delete(banned[i]);
	return paragraph.entries().next().value[0];
};
