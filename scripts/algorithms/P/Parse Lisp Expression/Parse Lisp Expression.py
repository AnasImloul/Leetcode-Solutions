# Runtime: 91 ms (Top 13.04%) | Memory: 14.3 MB (Top 9.42%)
class Solution:
    def evaluate(self, expression: str) -> int:
        stack = []
        parenEnd = {}

        # Get the end parenthesis location
        for idx, ch in enumerate(expression):
            if ch == '(':
                stack.append(idx)
            if ch == ')':
                parenEnd[stack.pop()] = idx

        # Parses the expression into a list, each new sublist is a set of parenthesis
        # Example:
        # Input: "(let x 2 (mult x (let x 3 y 4 (add x y))))"
        # Output: ['let', 'x', '2', ['mult', 'x', ['let', 'x', '3', 'y', '4', ['add', 'x', 'y']]]]
        def parse(lo, hi):
            arr = []
            word = []

            i = lo
            while i < hi:
                if expression[i] == '(':
                    arr.append(parse(i + 1, parenEnd[i]))
                    i = parenEnd[i]
                elif expression[i] == ' ' or expression[i] == ')' and word != []:
                    if ''.join(word) != '':
                        arr.append(''.join(word))
                    word = []
                    i += 1
                elif expression[i] != ')':
                    word.append(expression[i])
                    i += 1
                else:
                    i += 1

            if word != []:
                arr.append(''.join(word))

            return arr

        # Change string expression into the list expression
        expressionList = parse(1, len(expression) - 1)

        # Eval expression with starting scope (variables)
        return self.genEval(expressionList, {})

    def genEval(self, expression, scope):
        if type(expression) != list:
            # If expression is just a variable or int
            try:
                return int(expression)
            except:
                return scope[expression]
        else:
            if expression[0] == 'let':
                # Remove "let" from expression list
                expression = expression[1:]

                # This loop updates the scope (variables)
                while len(expression) > 2:
                    scope = self.letEval(expression, scope.copy())
                    expression = expression[2:]

                # Return the last value
                return self.genEval(expression[0], scope.copy())

            if expression[0] == 'add':
                return self.addEval(expression, scope.copy())

            if expression[0] == 'mult':
                return self.multEval(expression, scope.copy())

    def letEval(self, expression, scope):
        scope[expression[0]] = self.genEval(expression[1], scope)
        return scope

    def addEval(self, expression, scope):
        return self.genEval(expression[1], scope) + self.genEval(expression[2], scope)

    def multEval(self, expression, scope):
        return self.genEval(expression[1], scope) * self.genEval(expression[2], scope)
