<h3 align="left"> 1031. Maximum Sum of Two Non-Overlapping Subarrays</h3>
<div><p>Given an integer array <code>nums</code> and two integers <code>firstLen</code> and <code>secondLen</code>, return <em>the maximum sum of elements in two non-overlapping <strong>subarrays</strong> with lengths </em><code>firstLen</code><em> and </em><code>secondLen</code>.</p>

<p>The array with length <code>firstLen</code> could occur before or after the array with length <code>secondLen</code>, but they have to be non-overlapping.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
<strong>Output:</strong> 20
<strong>Explanation:</strong> One choice of subarrays is [9] with length 1, and [6,5] with length 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
<strong>Output:</strong> 29
<strong>Explanation:</strong> One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
<strong>Output:</strong> 31
<strong>Explanation:</strong> One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= firstLen, secondLen &lt;= 1000</code></li>
	<li><code>2 &lt;= firstLen + secondLen &lt;= 1000</code></li>
	<li><code>firstLen + secondLen &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>
</div>