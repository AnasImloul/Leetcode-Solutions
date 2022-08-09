	class CustomStack:

		def __init__(self, maxSize: int):
			self.size = maxSize
			self.stack = []

		def push(self, x: int) -> None:
			if self.size > len(self.stack):
				self.stack.append(x)

		def pop(self) -> int:
			if self.stack:
				return self.stack.pop()
			return -1

		def increment(self, k: int, val: int) -> None:
			len_stack = len(self.stack)

			if len_stack < k:
				self.stack[:] = [i + val for i in self.stack]
				return

			for i in range(k):
				self.stack[i] += val
