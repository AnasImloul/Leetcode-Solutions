<h3 align="left"> 2543. Check if Point Is Reachable</h3>
<div><p>There exists an infinitely large grid. You are currently at point <code>(1, 1)</code>, and you need to reach the point <code>(targetX, targetY)</code> using a finite number of steps.</p>

<p>In one <strong>step</strong>, you can move from point <code>(x, y)</code> to any one of the following points:</p>

<ul>
	<li><code>(x, y - x)</code></li>
	<li><code>(x - y, y)</code></li>
	<li><code>(2 * x, y)</code></li>
	<li><code>(x, 2 * y)</code></li>
</ul>

<p>Given two integers <code>targetX</code> and <code>targetY</code> representing the X-coordinate and Y-coordinate of your final position, return <code>true</code> <em>if you can reach the point from</em> <code>(1, 1)</code> <em>using some number of steps, and </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> targetX = 6, targetY = 9
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to reach (6,9) from (1,1) using any sequence of moves, so false is returned.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> targetX = 4, targetY = 7
<strong>Output:</strong> true
<strong>Explanation:</strong> You can follow the path (1,1) -&gt; (1,2) -&gt; (1,4) -&gt; (1,8) -&gt; (1,7) -&gt; (2,7) -&gt; (4,7).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= targetX, targetY&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>
</div>
