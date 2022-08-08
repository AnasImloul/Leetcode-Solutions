	class MapSum:

		def __init__(self):
			self.cache = {}

		def insert(self, key: str, val: int) -> None:
			self.cache[key] = val

		def sum(self, prefix: str) -> int:
			len_prefix = len(prefix)
			total = 0
			for word, value in self.cache.items():
				if word[: len_prefix] == prefix:
					total += value

			return total