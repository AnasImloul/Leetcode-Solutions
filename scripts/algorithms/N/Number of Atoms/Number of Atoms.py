// Runtime: 35 ms (Top 78.84%) | Memory: 16.70 MB (Top 50.21%)

class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack, elem, i = [{}], "", 0
        
        while i < len(formula):
            # Extract the full element name
            if formula[i].isupper():
                j = i + 1
                while j < len(formula) and formula[j].islower():
                    j += 1
                elem = formula[i:j]
                i = j
                # If no digits follow the element, assign a count of 1
                if i == len(formula) or not formula[i].isdigit() and not formula[i].islower():
                    stack[-1][elem] = stack[-1].get(elem, 0) + 1
            # Extract the count
            elif formula[i].isdigit():
                j = i
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                count = int(formula[i:j])
                stack[-1][elem] = stack[-1].get(elem, 0) + count
                i = j
            # Handle open parentheses by pushing a new dict
            elif formula[i] == '(':
                stack.append({})
                i += 1
            # Handle close parentheses by merging with the previous dict
            elif formula[i] == ')':
                i += 1
                j = i
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                multiplier = int(formula[i:j] or 1)
                top = stack.pop()
                for elem, count in top.items():
                    stack[-1][elem] = stack[-1].get(elem, 0) + count * multiplier
                i = j
        
        # Convert the result to the desired format
        atoms = sorted(stack[0].items())
        return ''.join([atom + (str(count) if count > 1 else '') for atom, count in atoms])

