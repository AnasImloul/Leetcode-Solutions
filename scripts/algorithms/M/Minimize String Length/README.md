<h3 align="left"> 2716. Minimize String Length</h3>
<div><p>Given a string <code>s</code>, you have two types of operation:</p>

<ol>
	<li>Choose an index <code>i</code> in the string, and let <code>c</code> be the character in position <code>i</code>. <strong>Delete</strong> the <strong>closest occurrence</strong> of <code>c</code> to the <strong>left</strong> of <code>i</code> (if exists).</li>
	<li>Choose an index <code>i</code> in the string, and let <code>c</code> be the character in position <code>i</code>. <strong>Delete</strong> the <strong>closest occurrence</strong> of <code>c</code> to the <strong>right</strong> of <code>i</code> (if exists).</li>
</ol>

<p>Your task is to <strong>minimize</strong> the length of <code>s</code> by performing the above operations zero or more times.</p>

<p>Return an integer denoting the length of the <strong>minimized</strong> string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aaabc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ol>
	<li>Operation 2: we choose <code>i = 1</code> so <code>c</code> is &#39;a&#39;, then we remove <code>s[2]</code> as it is closest &#39;a&#39; character to the right of <code>s[1]</code>.<br />
	<code>s</code> becomes &quot;aabc&quot; after this.</li>
	<li>Operation 1: we choose <code>i = 1</code> so <code>c</code> is &#39;a&#39;, then we remove <code>s[0]</code> as it is closest &#39;a&#39; character to the left of <code>s[1]</code>.<br />
	<code>s</code> becomes &quot;abc&quot; after this.</li>
</ol>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;cbbd&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ol>
	<li>Operation 1: we choose <code>i = 2</code> so <code>c</code> is &#39;b&#39;, then we remove <code>s[1]</code> as it is closest &#39;b&#39; character to the left of <code>s[1]</code>.<br />
	<code>s</code> becomes &quot;cbd&quot; after this.</li>
</ol>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;baadccab&quot;</span></p>

<p><strong>Output:</strong> 4</p>

<p><strong>Explanation:</strong></p>

<ol>
	<li>Operation 1: we choose <code>i = 6</code> so <code>c</code> is &#39;a&#39;, then we remove <code>s[2]</code> as it is closest &#39;a&#39; character to the left of <code>s[6]</code>.<br />
	<code>s</code> becomes &quot;badccab&quot; after this.</li>
	<li>Operation 2: we choose <code>i = 0</code> so <code>c</code> is &#39;b&#39;, then we remove <code>s[6]</code> as it is closest &#39;b&#39; character to the right of <code>s[0]</code>.<br />
	<code>s</code> becomes &quot;badcca&quot; fter this.</li>
	<li>Operation 2: we choose <code>i = 3</code> so <code>c</code> is &#39;c&#39;, then we remove <code>s[4]</code> as it is closest &#39;c&#39; character to the right of <code>s[3]</code>.<br />
	<code>s</code> becomes &quot;badca&quot; after this.</li>
	<li>Operation 1: we choose <code>i = 4</code> so <code>c</code> is &#39;a&#39;, then we remove <code>s[1]</code> as it is closest &#39;a&#39; character to the left of <code>s[4]</code>.<br />
	<code>s</code> becomes &quot;bdca&quot; after this.</li>
</ol>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> contains only lowercase English letters</li>
</ul>
</div>
