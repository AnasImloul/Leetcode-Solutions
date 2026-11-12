<h3 align="left"> 2826. Sorting Three Groups</h3>
<div><p>You are given an integer array <code>nums</code>. Each element in <code>nums</code> is 1, 2 or 3. In each operation, you can remove an element from&nbsp;<code>nums</code>. Return the <strong>minimum</strong> number of operations to make <code>nums</code> <strong>non-decreasing</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,1,3,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>One of the optimal solutions is to remove <code>nums[0]</code>, <code>nums[2]</code> and <code>nums[3]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,3,2,1,3,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>One of the optimal solutions is to remove <code>nums[1]</code> and <code>nums[2]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,2,2,2,3,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p><code>nums</code> is already non-decreasing.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 3</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:</strong> Can you come up with an algorithm that runs in <code>O(n)</code> time complexity?</div>
