<h3 align="left"> 1449. Form Largest Integer With Digits That Add up to Target</h3>
<div><p>Given an array of integers <code>cost</code> and an integer <code>target</code>, return <em>the <strong>maximum</strong> integer you can paint under the following rules</em>:</p>

<ul>
	<li>The cost of painting a digit <code>(i + 1)</code> is given by <code>cost[i]</code> (<strong>0-indexed</strong>).</li>
	<li>The total cost used must be equal to <code>target</code>.</li>
	<li>The integer does not have <code>0</code> digits.</li>
</ul>

<p>Since the answer may be very large, return it as a string. If there is no way to paint any integer given the condition, return <code>"0"</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> cost = [4,3,2,5,6,7,2,5,5], target = 9
<strong>Output:</strong> "7772"
<strong>Explanation:</strong> The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "977", but "7772" is the largest number.
<strong>Digit    cost</strong>
  1  -&gt;   4
  2  -&gt;   3
  3  -&gt;   2
  4  -&gt;   5
  5  -&gt;   6
  6  -&gt;   7
  7  -&gt;   2
  8  -&gt;   5
  9  -&gt;   5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> cost = [7,6,5,5,5,6,8,7,8], target = 12
<strong>Output:</strong> "85"
<strong>Explanation:</strong> The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> cost = [2,4,6,2,4,6,4,4,4], target = 5
<strong>Output:</strong> "0"
<strong>Explanation:</strong> It is impossible to paint any integer with total cost equal to target.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>cost.length == 9</code></li>
	<li><code>1 &lt;= cost[i], target &lt;= 5000</code></li>
</ul>
</div>