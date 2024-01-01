// Runtime: 3 ms (Top 93.12%) | Memory: 7.40 MB (Top 89.68%)

class Solution {
public:
    bool parseBoolExpr(string e) {
        auto it = e.begin();
        return parse(it);
    }

    bool parse(string::iterator& it) {
        switch (*(it++)) {
            case 't': return true;
            case 'f': return false;
            case '|': return parse(it, false, [](bool init, bool val){ return init || val; });
            case '&': return parse(it, true,  [](bool init, bool val){ return init && val; });
            case '!': return parse(it, false, [](bool init, bool val){ return !val; });
        }
        return false;
    }

    bool parse(string::iterator& it, bool init, function<bool(bool, bool)> op) {
        it++; // skip '('
        while (true) {
            auto b = parse(it);
            init = op(init, b);
            if (*it == ')') break;
            it++; // skip ','
        }
        it++; // skip ')'
        return init;
    }
};
