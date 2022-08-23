// Runtime: 4 ms (Top 79.58%) | Memory: 10.8 MB (Top 38.33%)
[[nodiscard]] double step(
    int const A, int const B, std::unordered_map<int, std::unordered_map<int, double>> & Memo )
{
    if( A <= 0 ) return B <= 0 ? 0.5 : 1.0;
    if( B <= 0 ) return 0.0;

    auto const AIt{ Memo.find(A) };

    if( Memo.cend() != AIt )
    {
        auto const BIt{ AIt->second.find(B) };
        if( AIt->second.cend() != BIt ) return BIt->second;
    }

    double M{ step( A-100, B, Memo ) };
    M += step( A-75, B-25, Memo );
    M += step( A-50, B-50, Memo );
    M += step( A-25, B-75, Memo );
    return Memo[A][B] = 0.25 * M;
}

class Solution
{
public:
    double soupServings(int n)
    {
        if( n > 4750 ) return 1;

        std::unordered_map<int, std::unordered_map<int, double>> Memo{};
        return step( n, n, Memo );
    }
};