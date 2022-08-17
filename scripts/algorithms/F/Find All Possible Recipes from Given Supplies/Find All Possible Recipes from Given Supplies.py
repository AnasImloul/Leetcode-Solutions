class Solution:
	def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:

		graph = defaultdict(list)
		in_degree = defaultdict(int)
		for r,ing in zip(recipes,ingredients):
			for i in ing:
				graph[i].append(r)
				in_degree[r]+=1

		queue = supplies[::]
		res = []
		while queue:
			ing = queue.pop(0)
			if ing in recipes:
				res.append(ing)

			for child in graph[ing]:
				in_degree[child]-=1
				if in_degree[child]==0:
					queue.append(child)

		return res
