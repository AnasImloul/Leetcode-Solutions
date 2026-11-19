<h3 align="left"> 2862. Maximum Element-Sum of a Complete Subset of Indices</h3>
<div><p>You are given a <strong>1</strong><strong>-indexed</strong> array <code>nums</code>. Your task is to select a <strong>complete subset</strong> from <code>nums</code> where every pair of selected indices multiplied is a <span data-keyword="perfect-square">perfect square,</span>. i. e. if you select <code>a<sub>i</sub></code> and <code>a<sub>j</sub></code>, <code>i * j</code> must be a perfect square.</p>

<p>Return the <em>sum</em> of the complete subset with the <em>maximum sum</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [8,7,3,5,7,2,4,9]</span></p>

<p><strong>Output:</strong> <span class="example-io">16</span></p>

<p><strong>Explanation:</strong></p>

<p>We select elements at indices 2 and 8 and <code>2 * 8</code> is a perfect square.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [8,10,3,8,1,13,7,9,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">20</span></p>

<p><strong>Explanation:</strong></p>

<p>We select elements at indices 1, 4, and 9. <code>1 * 4</code>, <code>1 * 9</code>, <code>4 * 9</code> are perfect squares.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>
