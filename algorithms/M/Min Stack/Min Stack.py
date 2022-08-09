class MinStack:

	def __init__(self):
		self.stack = []

	def push(self, val: int) -> None:
		if not self.stack:
			self.stack.append((val, val))
		else:
			self.stack.append((val, min(val, self.stack[-1][1])))

	def pop(self) -> None:
		if self.stack:
			self.stack.pop()

	def top(self) -> int:
		if self.stack:
			return self.stack[-1][0]
		else:
			return None

	def getMin(self) -> int:
		if self.stack:
			return self.stack[-1][1]
		else:
			return None
