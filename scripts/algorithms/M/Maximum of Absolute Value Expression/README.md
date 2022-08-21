<h3 align="left"> 1131. Maximum of Absolute Value Expression</h3>
<div><p>Given two arrays of integers with equal lengths, return the maximum value of:</p>

<p><code>|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|</code></p>

<p>where the maximum is taken over all <code>0 &lt;= i, j &lt; arr1.length</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
<strong>Output:</strong> 13
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
<strong>Output:</strong> 20
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr1.length == arr2.length &lt;= 40000</code></li>
	<li><code>-10^6 &lt;= arr1[i], arr2[i] &lt;= 10^6</code></li>
</ul>
</div>