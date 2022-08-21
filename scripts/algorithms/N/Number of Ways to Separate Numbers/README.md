<h3 align="left"> 1977. Number of Ways to Separate Numbers</h3>
<div><p>You wrote down many <strong>positive</strong> integers in a string called <code>num</code>. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was <strong>non-decreasing</strong> and that <strong>no</strong> integer had leading zeros.</p>

<p>Return <em>the <strong>number of possible lists of integers</strong> that you could have written down to get the string </em><code>num</code>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = "327"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You could have written down the numbers:
3, 27
327
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "094"
<strong>Output:</strong> 0
<strong>Explanation:</strong> No numbers can have leading zeros and all numbers must be positive.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "0"
<strong>Output:</strong> 0
<strong>Explanation:</strong> No numbers can have leading zeros and all numbers must be positive.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 3500</code></li>
	<li><code>num</code> consists of digits <code>'0'</code> through <code>'9'</code>.</li>
</ul>
</div>