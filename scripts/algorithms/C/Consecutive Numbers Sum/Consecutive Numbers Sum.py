# For every odd divisor d of n, there's exactly one sum of length d, e.g.
#
#     21 = 3 * 7 = 6 + 7 + 8.
#
# Also, every odd length sum is of this form, since the middle value is average,
# and the sum is just (number of elements) * (average) = d * n/d.
#
# For even length sums, the average is a half-integer
#
#     2 + 3 + 4 + 5 = 4 * 3.5
#
# So n can be written as
#
#     n = (even length) * (half-integer average)
#       = (2 * c) * (d / 2)
#       = c * d
#
# for some arbitrary integer c and odd integer d. So again, any odd d divisor of
# n produces an even length sum, and every even length sum is of this form.
#
# However, we need to ensure that the sum only contains positive integers.
#
# For the first case, the smallest number is n/d - (d-1)/2. For the second case,
# it's (d+1)/2 - n/d.
#
# For all d, exactly one of these is positive, and so every odd divisor
# corresponds to exactly one sum, and all sums are of this form.
#
# Therefore, we need to count the odd divisors.
#
# There's no way I know of doing this without essentially factoring the number.
# So say
#
#     n = 2**n0 * p1**n1 * p2**n2 * ... * pk**nk
#
# is the prime decomposition (all p are odd). Then n has
#
#     (n1+1) * (n2+1) * ... * (nk+1)
#
# odd divisors.
#
# For the implementation, we search the smallest divisor, which is neccessarily
# prime and divide by it as often as possible (and count the divisions). If
# after that p**2 > n, we know that n itself is prime.
#
# Complexity is O(sqrt(n)) in bad cases (if n is prime), but can be much better
# if n only has small prime factors, e.g. for n = 3**k it's O(k) = O(log(n)).

class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        while n % 2 == 0:
            # Kill even factors
            n //= 2
        result = 1
        p = 3
        while n != 1:
            count = 1
            while n % p == 0:
                n //= p
                count += 1
            result *= count
            if p**2 >= n:
                # Rest of n is prime, stop here
                if n > p:
                    # We have not counted n yet
                    result *= 2
                break
            p += 2
        return result
