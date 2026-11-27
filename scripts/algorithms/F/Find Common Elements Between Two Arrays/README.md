<h3 align="left"> 2956. Find Common Elements Between Two Arrays</h3>
<div><p>You are given two integer arrays <code>nums1</code> and <code>nums2</code> of sizes <code>n</code> and <code>m</code>, respectively. Calculate the following values:</p>

<ul>
	<li><code>answer1</code> : the number of indices <code>i</code> such that <code>nums1[i]</code> exists in <code>nums2</code>.</li>
	<li><code>answer2</code> : the number of indices <code>i</code> such that <code>nums2[i]</code> exists in <code>nums1</code>.</li>
</ul>

<p>Return <code>[answer1,answer2]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [2,3,2], nums2 = [1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,1]</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2024/05/26/3488_find_common_elements_between_two_arrays-t1.gif" style="width: 225px; height: 150px;" /></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">[3,4]</span></p>

<p><strong>Explanation:</strong></p>

<p>The elements at indices 1, 2, and 3 in <code>nums1</code> exist in <code>nums2</code> as well. So <code>answer1</code> is 3.</p>

<p>The elements at indices 0, 1, 3, and 4 in <code>nums2</code> exist in <code>nums1</code>. So <code>answer2</code> is 4.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [3,4,2,3], nums2 = [1,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,0]</span></p>

<p><strong>Explanation:</strong></p>

<p>No numbers are common between <code>nums1</code> and <code>nums2</code>, so answer is [0,0].</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>m == nums2.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>
</div>
