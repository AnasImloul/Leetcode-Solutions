<h3 align="left"> 1923. Longest Common Subpath</h3>
<div><p>There is a country of <code>n</code> cities numbered from <code>0</code> to <code>n - 1</code>. In this country, there is a road connecting <b>every pair</b> of cities.</p>

<p>There are <code>m</code> friends numbered from <code>0</code> to <code>m - 1</code> who are traveling through the country. Each one of them will take a path consisting of some cities. Each path is represented by an integer array that contains the visited cities in order. The path may contain a city <strong>more than once</strong>, but the same city will not be listed consecutively.</p>

<p>Given an integer <code>n</code> and a 2D integer array <code>paths</code> where <code>paths[i]</code> is an integer array representing the path of the <code>i<sup>th</sup></code> friend, return <em>the length of the <strong>longest common subpath</strong> that is shared by <strong>every</strong> friend's path, or </em><code>0</code><em> if there is no common subpath at all</em>.</p>

<p>A <strong>subpath</strong> of a path is a contiguous sequence of cities within that path.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5, paths = [[0,1,<u>2,3</u>,4],
                       [<u>2,3</u>,4],
                       [4,0,1,<u>2,3</u>]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest common subpath is [2,3].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, paths = [[0],[1],[2]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no common subpath shared by the three paths.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 5, paths = [[<u>0</u>,1,2,3,4],
                       [4,3,2,1,<u>0</u>]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The possible longest common subpaths are [0], [1], [2], [3], and [4]. All have a length of 1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>m == paths.length</code></li>
	<li><code>2 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>sum(paths[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= paths[i][j] &lt; n</code></li>
	<li>The same city is not listed multiple times consecutively in <code>paths[i]</code>.</li>
</ul>
</div>