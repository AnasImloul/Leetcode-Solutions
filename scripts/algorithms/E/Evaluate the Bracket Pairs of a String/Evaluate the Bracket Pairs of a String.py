class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        knowledge = dict(knowledge)
        answer, start = [], None
        for i, char in enumerate(s):
            if char == '(': 
                start = i + 1
            elif char == ')':
                answer.append(knowledge.get(s[start:i], '?'))
                start = None
            elif start is None: 
                answer.append(char)
        return ''.join(answer)
