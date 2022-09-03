# Runtime: 62 ms (Top 83.61%) | Memory: 14.1 MB (Top 62.30%)
class Term:
    def __init__(self, exp: Optional[str]='', *, term: Optional[Mapping[str, int]]={}) -> None:
        self.d = defaultdict(int, **term)
        if re.match(r'^\-?\d+$', exp):
            self.d[''] += int(exp)
        elif exp:
            self.d[exp] += 1

    def __add__(self, other: 'Term') -> 'Term':
        return self._pm(other, add=True)

    def __mul__(self, other: 'Term') -> 'Term':
        res = defaultdict(int)
        for (l_var, l_coef), (r_var, r_coef) in product(self.d.items(), other.d.items()):
            res['*'.join(sorted(self._exp(l_var)+self._exp(r_var)))] += l_coef*r_coef
        return Term(term=res)

    def __sub__(self, other: 'Term') -> 'Term':
        return self._pm(other, add=False)

    def get(self) -> List[str]:
        return [str(coef)+'*'*bool(var)+var \
                for var, coef in sorted(self.d.items(), key=lambda t: (-len(self._exp(t[0])), t[0])) if coef]

    def _exp(self, var: str) -> List[str]:
        return list(filter(bool, var.split('*')))

    def _pm(self, other: 'Term', *, add: bool) -> 'Term':
        res = copy.copy(self.d)
        for var, coef in other.d.items():
            res[var] += coef*(-1)**(1-add)
        return Term(term=res)

class Solution:
    def basicCalculatorIV(self, expression: str, evalvars: List[str], evalints: List[int]) -> List[str]:
        vals = dict(zip(evalvars, evalints))
        return eval(re.sub(r'[a-z0-9]+', lambda m: "Term('"+str(vals.get(m.group(), m.group()))+"')", expression)).get()