<h3 align="left"> 2318. Number of Distinct Roll Sequences</h3>
<div><p>You are given an integer <code>n</code>. You roll a fair 6-sided dice <code>n</code> times. Determine the total number of <strong>distinct</strong> sequences of rolls possible such that the following conditions are satisfied:</p>

<ol>
	<li>The <strong>greatest common divisor</strong> of any <strong>adjacent</strong> values in the sequence is equal to <code>1</code>.</li>
	<li>There is <strong>at least</strong> a gap of <code>2</code> rolls between <strong>equal</strong> valued rolls. More formally, if the value of the <code>i<sup>th</sup></code> roll is <strong>equal</strong> to the value of the <code>j<sup>th</sup></code> roll, then <code>abs(i - j) &gt; 2</code>.</li>
</ol>

<p>Return <em>the<strong> total number</strong> of distinct sequences possible</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>Two sequences are considered distinct if at least one element is different.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 184
<strong>Explanation:</strong> Some of the possible sequences are (1, 2, 3, 4), (6, 1, 2, 3), (1, 2, 3, 1), etc.
Some invalid sequences are (1, 2, 1, 3), (1, 2, 3, 6).
(1, 2, 1, 3) is invalid since the first and third roll have an equal value and abs(1 - 3) = 2 (i and j are 1-indexed).
(1, 2, 3, 6) is invalid since the greatest common divisor of 3 and 6 = 3.
There are a total of 184 distinct sequences possible, so we return 184.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 22
<strong>Explanation:</strong> Some of the possible sequences are (1, 2), (2, 1), (3, 2).
Some invalid sequences are (3, 6), (2, 4) since the greatest common divisor is not equal to 1.
There are a total of 22 distinct sequences possible, so we return 22.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>
</div>