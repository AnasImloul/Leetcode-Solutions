<h3 align="left"> 2104. Sum of Subarray Ranges</h3>
<div><p>You are given an integer array <code>nums</code>. The <strong>range</strong> of a subarray of <code>nums</code> is the difference between the largest and smallest element in the subarray.</p>

<p>Return <em>the <strong>sum of all</strong> subarray ranges of </em><code>nums</code><em>.</em></p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [4,-2,-3,4,1]
<strong>Output:</strong> 59
<strong>Explanation:</strong> The sum of all subarray ranges of nums is 59.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Could you find a solution with <code>O(n)</code> time complexity?</p>
</div>