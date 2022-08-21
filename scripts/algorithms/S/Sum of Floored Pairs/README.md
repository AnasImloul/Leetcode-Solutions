<h3 align="left"> 1862. Sum of Floored Pairs</h3>
<div><p>Given an integer array <code>nums</code>, return the sum of <code>floor(nums[i] / nums[j])</code> for all pairs of indices <code>0 &lt;= i, j &lt; nums.length</code> in the array. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>The <code>floor()</code> function returns the integer part of the division.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,5,9]
<strong>Output:</strong> 10
<strong>Explanation:</strong>
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
We calculate the floor of the division for every pair of indices in the array then sum them up.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [7,7,7,7,7,7,7]
<strong>Output:</strong> 49
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>