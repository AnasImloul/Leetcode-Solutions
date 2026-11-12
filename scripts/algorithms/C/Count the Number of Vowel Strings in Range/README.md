<h3 align="left"> 2586. Count the Number of Vowel Strings in Range</h3>
<div><p>You are given a <strong>0-indexed</strong> array of string <code>words</code> and two integers <code>left</code> and <code>right</code>.</p>

<p>A string is called a <strong>vowel string</strong> if it starts with a vowel character and ends with a vowel character where vowel characters are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>.</p>

<p>Return <em>the number of vowel strings </em><code>words[i]</code><em> where </em><code>i</code><em> belongs to the inclusive range </em><code>[left, right]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;are&quot;,&quot;amy&quot;,&quot;u&quot;], left = 0, right = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- &quot;are&quot; is a vowel string because it starts with &#39;a&#39; and ends with &#39;e&#39;.
- &quot;amy&quot; is not a vowel string because it does not end with a vowel.
- &quot;u&quot; is a vowel string because it starts with &#39;u&#39; and ends with &#39;u&#39;.
The number of vowel strings in the mentioned range is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;hey&quot;,&quot;aeo&quot;,&quot;mu&quot;,&quot;ooo&quot;,&quot;artro&quot;], left = 1, right = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
- &quot;aeo&quot; is a vowel string because it starts with &#39;a&#39; and ends with &#39;o&#39;.
- &quot;mu&quot; is not a vowel string because it does not start with a vowel.
- &quot;ooo&quot; is a vowel string because it starts with &#39;o&#39; and ends with &#39;o&#39;.
- &quot;artro&quot; is a vowel string because it starts with &#39;a&#39; and ends with &#39;o&#39;.
The number of vowel strings in the mentioned range is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists of only lowercase English letters.</li>
	<li><code>0 &lt;= left &lt;= right &lt; words.length</code></li>
</ul>
</div>
