<h3 align="left"> 1090. Largest Values From Labels</h3>
<div><p>There is a set of <code>n</code> items. You are given two integer arrays <code>values</code> and <code>labels</code> where the value and the label of the <code>i<sup>th</sup></code> element are <code>values[i]</code> and <code>labels[i]</code> respectively. You are also given two integers <code>numWanted</code> and <code>useLimit</code>.</p>

<p>Choose a subset <code>s</code> of the <code>n</code> elements such that:</p>

<ul>
	<li>The size of the subset <code>s</code> is <strong>less than or equal to</strong> <code>numWanted</code>.</li>
	<li>There are <strong>at most</strong> <code>useLimit</code> items with the same label in <code>s</code>.</li>
</ul>

<p>The <strong>score</strong> of a subset is the sum of the values in the subset.</p>

<p>Return <em>the maximum <strong>score</strong> of a subset </em><code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
<strong>Output:</strong> 9
<strong>Explanation:</strong> The subset chosen is the first, third, and fifth items.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
<strong>Output:</strong> 12
<strong>Explanation:</strong> The subset chosen is the first, second, and third items.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
<strong>Output:</strong> 16
<strong>Explanation:</strong> The subset chosen is the first and fourth items.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == values.length == labels.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= values[i], labels[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= numWanted, useLimit &lt;= n</code></li>
</ul>
</div>