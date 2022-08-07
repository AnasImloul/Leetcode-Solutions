/**
 * @param {number} n
 * @return {number}
 */
var checkRecord = function(n) {
  /**
   * P(n) = A(n - 1) + P(n - 1) + L(n - 1), n ≥ 2.
   * L(n) = A(n - 1) + P(n - 1) + A(n - 2) + P(n - 2), n ≥ 3.
   * A(n) = A(n - 1) + A(n - 2) + A(n - 3), n ≥ 4.
   */
  const m = 1000000007;
  const P = Array(n);
  const A = Array(n);
  const L = Array(n);
  A[0] = 1;
  L[0] = 1;
  P[0] = 1;
  A[1] = 2;
  A[2] = 4;
  L[1] = 3;
  for (let i = 1; i < n; i++) {
    P[i] = (A[i - 1] + L[i - 1] + P[i - 1]) % m;
    if (i >= 3) A[i] = (A[i - 1] + A[i - 2] + A[i - 3]) % m;
    if (i >= 2) L[i] = (A[i - 1] + P[i - 1] + A[i - 2] + P[i - 2]) % m;
  }
  return (P[n - 1] + A[n - 1] + L[n - 1]) % m;
};
