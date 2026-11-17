<h3 align="left"> 2828. Check if a String Is an Acronym of Words</h3>
<div><p>Given an array of strings <code>words</code> and a string <code>s</code>, determine if <code>s</code> is an <strong>acronym</strong> of words.</p>

<p>The string <code>s</code> is considered an acronym of <code>words</code> if it can be formed by concatenating the <strong>first</strong> character of each string in <code>words</code> <strong>in order</strong>. For example, <code>&quot;ab&quot;</code> can be formed from <code>[&quot;apple&quot;, &quot;banana&quot;]</code>, but it can&#39;t be formed from <code>[&quot;bear&quot;, &quot;aardvark&quot;]</code>.</p>

<p>Return <code>true</code><em> if </em><code>s</code><em> is an acronym of </em><code>words</code><em>, and </em><code>false</code><em> otherwise. </em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;alice&quot;,&quot;bob&quot;,&quot;charlie&quot;], s = &quot;abc&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> The first character in the words &quot;alice&quot;, &quot;bob&quot;, and &quot;charlie&quot; are &#39;a&#39;, &#39;b&#39;, and &#39;c&#39;, respectively. Hence, s = &quot;abc&quot; is the acronym. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;an&quot;,&quot;apple&quot;], s = &quot;a&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> The first character in the words &quot;an&quot; and &quot;apple&quot; are &#39;a&#39; and &#39;a&#39;, respectively. 
The acronym formed by concatenating these characters is &quot;aa&quot;. 
Hence, s = &quot;a&quot; is not the acronym.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;never&quot;,&quot;gonna&quot;,&quot;give&quot;,&quot;up&quot;,&quot;on&quot;,&quot;you&quot;], s = &quot;ngguoy&quot;
<strong>Output:</strong> true
<strong>Explanation: </strong>By concatenating the first character of the words in the array, we get the string &quot;ngguoy&quot;. 
Hence, s = &quot;ngguoy&quot; is the acronym.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>words[i]</code> and <code>s</code> consist of lowercase English letters.</li>
</ul>
</div>
