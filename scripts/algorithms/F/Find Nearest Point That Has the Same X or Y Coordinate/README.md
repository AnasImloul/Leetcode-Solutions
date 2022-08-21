<h3 align="left"> 1779. Find Nearest Point That Has the Same X or Y Coordinate</h3>
<div><p>You are given two integers, <code>x</code> and <code>y</code>, which represent your current location on a Cartesian grid: <code>(x, y)</code>. You are also given an array <code>points</code> where each <code>points[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> represents that a point exists at <code>(a<sub>i</sub>, b<sub>i</sub>)</code>. A point is <strong>valid</strong> if it shares the same x-coordinate or the same y-coordinate as your location.</p>

<p>Return <em>the index <strong>(0-indexed)</strong> of the <strong>valid</strong> point with the smallest <strong>Manhattan distance</strong> from your current location</em>. If there are multiple, return <em>the valid point with the <strong>smallest</strong> index</em>. If there are no valid points, return <code>-1</code>.</p>

<p>The <strong>Manhattan distance</strong> between two points <code>(x<sub>1</sub>, y<sub>1</sub>)</code> and <code>(x<sub>2</sub>, y<sub>2</sub>)</code> is <code>abs(x<sub>1</sub> - x<sub>2</sub>) + abs(y<sub>1</sub> - y<sub>2</sub>)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> x = 3, y = 4, points = [[3,4]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The answer is allowed to be on the same location as your current location.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> x = 3, y = 4, points = [[2,3]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no valid points.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>1 &lt;= x, y, a<sub>i</sub>, b<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>
</div>