<h3 align="left"> 2644. Find the Maximum Divisibility Score</h3>
<div><p>You are given two integer arrays <code>nums</code> and <code>divisors</code>.</p>

<p>The <strong>divisibility score</strong> of <code>divisors[i]</code> is the number of indices <code>j</code> such that <code>nums[j]</code> is divisible by <code>divisors[i]</code>.</p>

<p>Return the integer <code>divisors[i]</code> with the <strong>maximum</strong> divisibility score. If multiple integers have the maximum score, return the smallest one.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,9,15,50], divisors = [5,3,7,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The divisibility score of <code>divisors[0]</code> is 2 since <code>nums[2]</code> and <code>nums[3]</code> are divisible by 5.</p>

<p>The divisibility score of <code>divisors[1]</code> is 2 since <code>nums[1]</code> and <code>nums[2]</code> are divisible by 3.</p>

<p>The divisibility score of <code>divisors[2]</code> is 0 since none of the numbers in <code>nums</code> is divisible by 7.</p>

<p>The divisibility score of <code>divisors[3]</code> is 2 since <code>nums[0]</code> and <code>nums[3]</code> are divisible by 2.</p>

<p>As <code>divisors[0]</code>,&nbsp;<code>divisors[1]</code>, and <code>divisors[3]</code> have the same divisibility score, we return the smaller one which is <code>divisors[3]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,7,9,3,9], divisors = [5,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The divisibility score of <code>divisors[0]</code> is 0 since none of numbers in <code>nums</code> is divisible by 5.</p>

<p>The divisibility score of <code>divisors[1]</code> is 1 since only <code>nums[0]</code> is divisible by 2.</p>

<p>The divisibility score of <code>divisors[2]</code> is 3 since <code>nums[2]</code>, <code>nums[3]</code> and <code>nums[4]</code> are divisible by 3.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [20,14,21,10], divisors = [10,16,20]</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>The divisibility score of <code>divisors[0]</code> is 2 since <code>nums[0]</code> and <code>nums[3]</code> are divisible by 10.</p>

<p>The divisibility score of <code>divisors[1]</code> is 0 since none of the numbers in <code>nums</code> is divisible by 16.</p>

<p>The divisibility score of <code>divisors[2]</code> is 1 since <code>nums[0]</code> is divisible by 20.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, divisors.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], divisors[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>
