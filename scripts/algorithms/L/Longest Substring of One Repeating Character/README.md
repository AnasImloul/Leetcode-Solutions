<h3 align="left"> 2213. Longest Substring of One Repeating Character</h3>
<div><p>You are given a <strong>0-indexed</strong> string <code>s</code>. You are also given a <strong>0-indexed</strong> string <code>queryCharacters</code> of length <code>k</code> and a <strong>0-indexed</strong> array of integer <strong>indices</strong> <code>queryIndices</code> of length <code>k</code>, both of which are used to describe <code>k</code> queries.</p>

<p>The <code>i<sup>th</sup></code> query updates the character in <code>s</code> at index <code>queryIndices[i]</code> to the character <code>queryCharacters[i]</code>.</p>

<p>Return <em>an array</em> <code>lengths</code> <em>of length </em><code>k</code><em> where</em> <code>lengths[i]</code> <em>is the <strong>length</strong> of the <strong>longest substring</strong> of </em><code>s</code><em> consisting of <strong>only one repeating</strong> character <strong>after</strong> the</em> <code>i<sup>th</sup></code> <em>query</em><em> is performed.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
<strong>Output:</strong> [3,3,4]
<strong>Explanation:</strong> 
- 1<sup>st</sup> query updates s = "<u>b<strong>b</strong>b</u>acc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2<sup>nd</sup> query updates s = "bbb<u><strong>c</strong>cc</u>". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3<sup>rd</sup> query updates s = "<u>bbb<strong>b</strong></u>cc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong>
- 1<sup>st</sup> query updates s = "ab<strong>a</strong><u>zz</u>". The longest substring consisting of one repeating character is "zz" with length 2.
- 2<sup>nd</sup> query updates s = "<u>a<strong>a</strong>a</u>zz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>k == queryCharacters.length == queryIndices.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>queryCharacters</code> consists of lowercase English letters.</li>
	<li><code>0 &lt;= queryIndices[i] &lt; s.length</code></li>
</ul>
</div>