<h3 align="left"> 1124. Longest Well-Performing Interval</h3>
<div><p>We are given <code>hours</code>, a list of the number of hours worked per day for a given employee.</p>

<p>A day is considered to be a <em>tiring day</em> if and only if the number of hours worked is (strictly) greater than <code>8</code>.</p>

<p>A <em>well-performing interval</em> is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.</p>

<p>Return the length of the longest well-performing interval.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> hours = [9,9,6,0,6,6,9]
<strong>Output:</strong> 3
<strong>Explanation: </strong>The longest well-performing interval is [9,9,6].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> hours = [6,6,6]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= hours.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= hours[i] &lt;= 16</code></li>
</ul>
</div>