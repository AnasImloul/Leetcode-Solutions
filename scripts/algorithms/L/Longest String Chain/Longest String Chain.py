class Solution:
	def find(self, word, refer):
		# stack = [(word, level)]
		stack = [(word, 1)]
		# keep the maximum level(deepest) we have go through
		max_level = 1
		visited = set()
		while stack:
			char, level = stack.pop()
			for i in range(len(char)+1):
				# create all the possible transformation if we replace one character with *
				# for example: ab -> a*, *b
				possible = char[:i] + '*' + char[i:]
				if possible in refer and possible not in visited:
					visited.add(possible)
					for w in refer[possible]:
						max_level = max(level+1, max_level)
						stack.append((w, level+1))

		return max_level

	def longestStrChain(self, words: List[str]) -> int:
		map_dict = defaultdict(list)
		res = 1
		for w in words:
			for i in range(len(w)):
				# get all possible next char
				# for example: a -> a*, *a; ab -> ab*, a*b, *ab
				transform = w[:i] + '*' + w[i+1:]
				map_dict[transform].append(w)
				# map_dict: {'*a': ['a'], 'a*': ['a'] ...}

		words = sorted(words, key=len)
		for i, w in enumerate(words):
			ans = self.find(w, map_dict)
			res = max(res, ans)
		return res