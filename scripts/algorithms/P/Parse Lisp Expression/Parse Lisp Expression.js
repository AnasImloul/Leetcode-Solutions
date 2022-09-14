// Runtime: 149 ms (Top 25.00%) | Memory: 46.7 MB (Top 37.50%)
/**
 * @param {string} expression
 * @return {number}
 */
var evaluate = function(expression) {
    return helper(expression);
};

const helper = (expr, map = {}) => {
    if (expr[0] !== '(')
        return /[0-9]|-/.test(expr[0]) ? +expr : map[expr];

    map = Object.assign({}, map);
    const start = expr[1] === 'm' ? 6 : 5;
    const tokens = parse(expr.slice(start, expr.length - 1));

    if (expr.startsWith('(m')) return helper(tokens[0], map) * helper(tokens[1], map);
    if (expr.startsWith('(a')) return helper(tokens[0], map) + helper(tokens[1], map);

    for (let i = 0; i < tokens.length - 2; i += 2)
        map[tokens[i]] = helper(tokens[i + 1], map);

    return helper(tokens.at(-1), map);
}

const parse = expr => {
    const tokens = [];
    let [builder, par] = ['', 0];

    for (let ch of expr) {
        if (ch === '(') par++;
        if (ch === ')') par--;
        if (!par && ch === ' ') {
            tokens.push(builder);
            builder = '';
        }
        else builder += ch;
    }

    return builder ? [...tokens, builder] : tokens;
}