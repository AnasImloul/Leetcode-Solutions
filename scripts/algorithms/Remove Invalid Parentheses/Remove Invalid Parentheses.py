from functools import cache
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        
        @cache
        def getValid(s, parentheses):
            valid = set()
            output = ""
            for i in range( len(s) ):
                if s[i] == '(':
                    # case 1
                    next_valids = getValid( s[i+1:], parentheses)
                    for v in next_valids:
                        valid.add( output+v )
                    # case 2
                    output += s[i]
                    parentheses += 1
                elif s[i] == ')':
                    if parentheses == 0:
                        continue
                    else:
                        # case 1
                        next_valids = getValid( s[i+1:], parentheses)
                        for v in next_valids:
                            valid.add( output+v )
                        # case 2
                        output += s[i]
                        parentheses -= 1
                else:
                    output += s[i]
            if parentheses == 0:
                valid.add( output )
            return valid
        
        output = list( getValid(s,0) )
        if not output:
            output.append("")
        max_len = max( [len(i) for i in output])
        output = filter( lambda x: len(x)==max_len, output)
        return output
