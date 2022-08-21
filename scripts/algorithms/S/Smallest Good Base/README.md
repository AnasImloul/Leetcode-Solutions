<h3 align="left"> 483. Smallest Good Base</h3>
<div><p>Given an integer <code>n</code> represented as a string, return <em>the smallest <strong>good base</strong> of</em> <code>n</code>.</p>

<p>We call <code>k &gt;= 2</code> a <strong>good base</strong> of <code>n</code>, if all digits of <code>n</code> base <code>k</code> are <code>1</code>'s.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = "13"
<strong>Output:</strong> "3"
<strong>Explanation:</strong> 13 base 3 is 111.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = "4681"
<strong>Output:</strong> "8"
<strong>Explanation:</strong> 4681 base 8 is 11111.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = "1000000000000000000"
<strong>Output:</strong> "999999999999999999"
<strong>Explanation:</strong> 1000000000000000000 base 999999999999999999 is 11.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n</code> is an integer in the range <code>[3, 10<sup>18</sup>]</code>.</li>
	<li><code>n</code> does not contain any leading zeros.</li>
</ul>
</div>