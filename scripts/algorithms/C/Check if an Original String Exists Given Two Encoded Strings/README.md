<h3 align="left"> 2060. Check if an Original String Exists Given Two Encoded Strings</h3>
<div><p>An original string, consisting of lowercase English letters, can be encoded by the following steps:</p>

<ul>
	<li>Arbitrarily <strong>split</strong> it into a <strong>sequence</strong> of some number of <strong>non-empty</strong> substrings.</li>
	<li>Arbitrarily choose some elements (possibly none) of the sequence, and <strong>replace</strong> each with <strong>its length</strong> (as a numeric string).</li>
	<li><strong>Concatenate</strong> the sequence as the encoded string.</li>
</ul>

<p>For example, <strong>one way</strong> to encode an original string <code>"abcdefghijklmnop"</code> might be:</p>

<ul>
	<li>Split it as a sequence: <code>["ab", "cdefghijklmn", "o", "p"]</code>.</li>
	<li>Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes <code>["ab", "12", "1", "p"]</code>.</li>
	<li>Concatenate the elements of the sequence to get the encoded string: <code>"ab121p"</code>.</li>
</ul>

<p>Given two encoded strings <code>s1</code> and <code>s2</code>, consisting of lowercase English letters and digits <code>1-9</code> (inclusive), return <code>true</code><em> if there exists an original string that could be encoded as <strong>both</strong> </em><code>s1</code><em> and </em><code>s2</code><em>. Otherwise, return </em><code>false</code>.</p>

<p><strong>Note</strong>: The test cases are generated such that the number of consecutive digits in <code>s1</code> and <code>s2</code> does not exceed <code>3</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "internationalization", s2 = "i18n"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is possible that "internationalization" was the original string.
- "internationalization" 
  -&gt; Split:       ["internationalization"]
  -&gt; Do not replace any element
  -&gt; Concatenate:  "internationalization", which is s1.
- "internationalization"
  -&gt; Split:       ["i", "nternationalizatio", "n"]
  -&gt; Replace:     ["i", "18",                 "n"]
  -&gt; Concatenate:  "i18n", which is s2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "l123e", s2 = "44"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is possible that "leetcode" was the original string.
- "leetcode" 
  -&gt; Split:      ["l", "e", "et", "cod", "e"]
  -&gt; Replace:    ["l", "1", "2",  "3",   "e"]
  -&gt; Concatenate: "l123e", which is s1.
- "leetcode" 
  -&gt; Split:      ["leet", "code"]
  -&gt; Replace:    ["4",    "4"]
  -&gt; Concatenate: "44", which is s2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s1 = "a5b", s2 = "c5b"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible.
- The original string encoded as s1 must start with the letter 'a'.
- The original string encoded as s2 must start with the letter 'c'.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 40</code></li>
	<li><code>s1</code> and <code>s2</code> consist of digits <code>1-9</code> (inclusive), and lowercase English letters only.</li>
	<li>The number of consecutive digits in <code>s1</code> and <code>s2</code> does not exceed <code>3</code>.</li>
</ul>
</div>