// Runtime: 4090 ms (Top 34.15%) | Memory: 51.70 MB (Top 78.05%)

class Solution:
    def longestCommonSubpath(self, n, paths) -> int:
        def get_common_subpath_hashes(k):
            """Return hash values of common subpaths of length k, or empty set if none exists"""
            def get_subpath_hashes(path):
                hash, coeff = 0, pow(n, k-1, mod)
                for i in range(len(path)+1):
                    if i < k:
                        hash = (hash*n + path[i]) % mod
                    else:
                        yield hash
                        if i < len(path):
                            hash = ((hash-coeff*path[i-k])*n + path[i]) % mod   
            return reduce(set.intersection, (set(get_subpath_hashes(p)) for p in paths))
        
	    # can be replaced with a pre-computed large prime
        mod = self._generate_large_prime(int(1e18), int(9e18))
        low, high = 1, min(len(p) for p in paths)+1
        while low < high:
            mid = (low+high) // 2
            if get_common_subpath_hashes(mid):
                low = mid + 1
            else:
                high = mid
        return high - 1
    
    def _generate_large_prime(self, lower, upper):
        """Generate a prime between [lower, upper)"""
        def is_prime(n, trials=50):
            def witness(a, n):
                x0 = pow(a, u, n)
                for _ in range(t):
                    x = x0**2 % n
                    if x == 1 and x0 != 1 and x0 != n-1:
                        return True
                    x0 = x
                return True if x0 != 1 else False

            t, u = 0, n-1
            while u%2 == 0:
                t, u = t+1, u>>1
            return not any(witness(randrange(1, n), n) for _ in range(trials))
        return next(r for r in iter(lambda: randrange(lower, upper), None) if is_prime(r))
