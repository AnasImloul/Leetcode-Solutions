<h3 align="left"> 2057. Smallest Index With Equal Value</h3>
<div><p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, return <em>the <strong>smallest</strong> index </em><code>i</code><em> of </em><code>nums</code><em> such that </em><code>i mod 10 == nums[i]</code><em>, or </em><code>-1</code><em> if such index does not exist</em>.</p>

<p><code>x mod y</code> denotes the <strong>remainder</strong> when <code>x</code> is divided by <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
i=0: 0 mod 10 = 0 == nums[0].
i=1: 1 mod 10 = 1 == nums[1].
i=2: 2 mod 10 = 2 == nums[2].
All indices have i mod 10 == nums[i], so we return the smallest index 0.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,3,2,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
i=0: 0 mod 10 = 0 != nums[0].
i=1: 1 mod 10 = 1 != nums[1].
i=2: 2 mod 10 = 2 == nums[2].
i=3: 3 mod 10 = 3 != nums[3].
2 is the only index which has i mod 10 == nums[i].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5,6,7,8,9,0]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No index satisfies i mod 10 == nums[i].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>
</div>