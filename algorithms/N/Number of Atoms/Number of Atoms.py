from collections import Counter, deque

class Solution:
    def countOfAtoms(self, formula: str) -> str:
        """
        parser:
            formula: elem {count} formula
            elem: term | ( formula )
            term: [A-Z](a-z)+
            count: [0-9]+
        """
        
        
        def parse_formula(dq, allCount=Counter()):
            lhs = parse_elem(dq)
            count = 1
            while dq and dq[0].isdigit():
                count = parse_count(dq)
            for k in lhs.keys():
                allCount[k] += lhs[k] * count

            if dq and dq[0] not in ')':
                return parse_formula(dq, allCount)
            else:
                return allCount

        def parse_elem(dq):
            if dq and dq[0] == '(':
                dq.popleft()
                res = parse_formula(dq, Counter())
                dq.popleft()
                return res
            else:
                elem = ''
                if dq and dq[0].isupper():
                    elem += dq.popleft()
                    while dq and dq[0].islower():
                        elem += dq.popleft()
                return {elem: 1}

        def parse_count(dq):
            c = 0
            while dq and dq[0].isdigit():
                c = c * 10 + int(dq.popleft())
            return c

        formula = deque(formula)
        count_result = parse_formula(formula)
        result = ''
        for k in sorted(count_result.keys()):
            v = count_result[k]
            if v == 1:
                result += k
            else:
                result += f"{k}{count_result[k]}"
        return result
