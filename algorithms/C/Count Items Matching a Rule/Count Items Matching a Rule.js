const RULE_IDX = {
    'type': 0,
    'color': 1,
    'name': 2
};

var countMatches = function(items, ruleKey, ruleValue) {
    return items.reduce((ans, item) => item[RULE_IDX[ruleKey]] === ruleValue ? ans + 1 : ans, 0);
};
