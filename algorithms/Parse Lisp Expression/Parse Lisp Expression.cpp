class Context {
  unordered_map<string_view, int> _map;
  const Context *_parent{};
  public:
  Context(const Context *parent) : _parent{parent}
  {
    ;
  }
  const Context* Parent() const { return _parent; }
  int GetValue(const string_view &key) const
  {
    auto it = _map.find(key);
    if (it != _map.end()) return it->second;
    if (_parent) return _parent->GetValue(key);
    assert(0);
    return numeric_limits<int>::min();
  }
  void AddValue(const string_view &key, int val) {
    auto [it, isInserted] = _map.emplace(key, val);
    if (!isInserted) it->second = val;
  }
};
class Solution {
  string_view symbol(string_view &expr) {
    string_view ret;
    if (expr.empty() || !isalpha(expr[0])) {
      return ret;
    }
    auto pos = expr.find_first_of(" )");
    assert(pos != string_view::npos);
    ret = expr.substr(0, pos);
    expr.remove_prefix(pos);
    return ret;
  }
  int evaluate(string_view &expr, Context *context) {
    assert(!expr.empty());
    if (expr[0] == '(') {
      assert(expr.length() >= 4);
      if (expr.substr(0, 4) == "(add") {
        assert(expr.length() > 4);
        expr.remove_prefix(4);
        assert(!expr.empty() && expr[0] == ' ');
        expr.remove_prefix(1);
        int l = evaluate(expr, context);
        assert(!expr.empty() && expr[0] == ' ');
        expr.remove_prefix(1);
        int r = evaluate(expr, context);
        assert(!expr.empty() && expr[0] == ')');
        expr.remove_prefix(1);
        return l + r;
      }
      if (expr.substr(0, 4) == "(mul") {
        assert(expr.length() > 5);
        expr.remove_prefix(5);
        assert(!expr.empty() && expr[0] == ' ');
        expr.remove_prefix(1);
        int l = evaluate(expr, context);
        assert(!expr.empty() && expr[0] == ' ');
        expr.remove_prefix(1);
        int r = evaluate(expr, context);
        assert(!expr.empty() && expr[0] == ')');
        expr.remove_prefix(1);
        return l * r;
      }
      if (expr.substr(0, 4) == "(let") {
        assert(expr.length() > 4);
        expr.remove_prefix(4);
        Context nc(context);
        while (1) {
          assert(!expr.empty() && expr[0] == ' ');
          expr.remove_prefix(1);
          string_view sym = symbol(expr);
          assert(!expr.empty());
          if (sym.empty() || expr[0] == ')') {
            int ret{};
            if (sym.empty()) {
              ret = evaluate(expr, &nc);
            } else {
              ret = nc.GetValue(sym);
            }
            assert(!expr.empty() && expr[0] == ')');
            expr.remove_prefix(1);
            return ret;
          }
          assert(!expr.empty() && expr[0] == ' ');
          expr.remove_prefix(1);
          int value = evaluate(expr, &nc);
          nc.AddValue(sym, value);
        }
        assert(0);
      }
    } 
    if (isdigit(expr[0]) || expr[0] == '-') {
      auto pos = expr.find_first_not_of("-0123456789");
      auto len = min(expr.length(), pos);
      int num;
      if (auto [ptr, ec] = from_chars(expr.data(), expr.data()+len, num); ec == errc()) {
        expr.remove_prefix(len);
      } else {
        assert(0);
      }
      return num;
    }
    if (isalpha(expr[0])) {
      string_view sym = symbol(expr);
      assert(!expr.empty() && (expr[0] == ' ' || expr[0] == ')'));
      return context->GetValue(sym);
    }
    assert(0);
    return numeric_limits<int>::min();
  }
public:
    int evaluate(string expression) {
      string_view expr(expression);
      Context context(nullptr);
      return evaluate(expr, &context);
    }
};
