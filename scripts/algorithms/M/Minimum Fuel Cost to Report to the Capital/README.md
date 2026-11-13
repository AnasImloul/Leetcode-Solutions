<h3 align="left"> 2477. Minimum Fuel Cost to Report to the Capital</h3>
<div><p>There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of <code>n</code> cities numbered from <code>0</code> to <code>n - 1</code> and exactly <code>n - 1</code> roads. The capital city is city <code>0</code>. You are given a 2D integer array <code>roads</code> where <code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists a <strong>bidirectional road</strong> connecting cities <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>

<p>There is a meeting for the representatives of each city. The meeting is in the capital city.</p>

<p>There is a car in each city. You are given an integer <code>seats</code> that indicates the number of seats in each car.</p>

<p>A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.</p>

<p>Return <em>the minimum number of liters of fuel to reach the capital city</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/22/a4c380025e3ff0c379525e96a7d63a3.png" style="width: 303px; height: 332px;" />
<pre>
<strong>Input:</strong> roads = [[0,1],[0,2],[0,3]], seats = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
- Representative<sub>1</sub> goes directly to the capital with 1 liter of fuel.
- Representative<sub>2</sub> goes directly to the capital with 1 liter of fuel.
- Representative<sub>3</sub> goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum. 
It can be proven that 3 is the minimum number of liters of fuel needed.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/11/16/2.png" style="width: 274px; height: 340px;" />
<pre>
<strong>Input:</strong> roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> 
- Representative<sub>2</sub> goes directly to city 3 with 1 liter of fuel.
- Representative<sub>2</sub> and representative<sub>3</sub> go together to city 1 with 1 liter of fuel.
- Representative<sub>2</sub> and representative<sub>3</sub> go together to the capital with 1 liter of fuel.
- Representative<sub>1</sub> goes directly to the capital with 1 liter of fuel.
- Representative<sub>5</sub> goes directly to the capital with 1 liter of fuel.
- Representative<sub>6</sub> goes directly to city 4 with 1 liter of fuel.
- Representative<sub>4</sub> and representative<sub>6</sub> go together to the capital with 1 liter of fuel.
It costs 7 liters of fuel at minimum. 
It can be proven that 7 is the minimum number of liters of fuel needed.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/09/27/efcf7f7be6830b8763639cfd01b690a.png" style="width: 108px; height: 86px;" />
<pre>
<strong>Input:</strong> roads = [], seats = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> No representatives need to travel to the capital city.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>roads.length == n - 1</code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>roads</code> represents a valid tree.</li>
	<li><code>1 &lt;= seats &lt;= 10<sup>5</sup></code></li>
</ul>
</div>
