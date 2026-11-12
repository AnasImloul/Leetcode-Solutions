<h3 align="left"> 2815. Max Pair Sum in an Array</h3>
<div><p>You are given an integer array <code>nums</code>. You have to find the <strong>maximum</strong> sum of a pair of numbers from <code>nums</code> such that the <strong>largest digit </strong>in both numbers is equal.</p>

<p>For example, 2373 is made up of three distinct digits: 2, 3, and 7, where 7 is the largest among them.</p>

<p>Return the <strong>maximum</strong> sum or -1 if no such pair exists.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [112,131,411]</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p>Each numbers largest digit in order is [2,3,4].</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2536,1613,3366,162]</span></p>

<p><strong>Output:</strong> <span class="example-io">5902</span></p>

<p><strong>Explanation:</strong></p>

<p>All the numbers have 6 as their largest digit, so the answer is <span class="example-io">2536 + 3366 = 5902.</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [51,71,17,24,42]</span></p>

<p><strong>Output:</strong> <span class="example-io">88</span></p>

<p><strong>Explanation:</strong></p>

<p>Each number&#39;s largest digit in order is [5,7,7,4,4].</p>

<p>So we have only two possible pairs, 71 + 17 = 88 and 24 + 42 = 66.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>
</div>
