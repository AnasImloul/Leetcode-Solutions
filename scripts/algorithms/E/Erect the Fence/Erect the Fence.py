class Solution:

    """Compute the convex hull of a set of points.

        Use Andrew's Monotone Chain algorithm, which has order O(N log(N)),
        where N is the number of input points.
    """

    def cross(self, p, a, b):
        """Return the cross product of the vectors p -> a and p -> b."""
        return (a[0] - p[0]) * (b[1] - p[1]) \
            - (a[1] - p[1]) * (b[0] - p[0])

    def _convex_hull_monotone_chain(self, points):
        """Compute the convex hull of a list of points.
        
        Use Andrew's Monotone Chain algorithm, which is similar to Graham Scan,
        except that it doesn't require sorting the points by angle.  This algorithm
        takes O(N log(N)) time, where N is len(points).
        """
        # Ensure all points are unique, and sort lexicographically.
        points = list(sorted(set(points)))
        
        # If there are fewer than three points, they must form a hull.
        if len(points) <= 2:
            return points
        
        # Compute the lower and upper portion of the hull.
        lower, upper = [], []
        for out, it in ((lower, points), (upper, reversed(points))):
            for p in it:
                while len(out) >= 2 and self.cross(out[-2], out[-1], p) > 0:
                    out.pop()
                out.append(p)

        # Concatenate the upper and lower hulls.  Remove the last point from each
        # because those points are duplicated in both upper and lower.
        return lower[:-1] + upper[:-1]

    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        """
        Find the convex hull of a collection of points.
        Return a list of indices of points forming the hull in clockwise order,
        starting with the leftmost point.
        """
        # Convert input points to tuples.
        points = [tuple(p) for p in trees]
        ans = set()
        for point in self._convex_hull_monotone_chain(points):
            ans.add(point)
        return ans