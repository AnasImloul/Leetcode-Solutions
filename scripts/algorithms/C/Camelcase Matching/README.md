<h3 align="left"> 1023. Camelcase Matching</h3>
<div><p>Given an array of strings <code>queries</code> and a string <code>pattern</code>, return a boolean array <code>answer</code> where <code>answer[i]</code> is <code>true</code> if <code>queries[i]</code> matches <code>pattern</code>, and <code>false</code> otherwise.</p>

<p>A query word <code>queries[i]</code> matches <code>pattern</code> if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
<strong>Output:</strong> [true,false,true,true,false]
<strong>Explanation:</strong> "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
<strong>Output:</strong> [true,false,true,false,false]
<strong>Explanation:</strong> "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
<strong>Output:</strong> [false,true,false,false,false]
<strong>Explanation:</strong> "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length, queries.length &lt;= 100</code></li>
	<li><code>1 &lt;= queries[i].length &lt;= 100</code></li>
	<li><code>queries[i]</code> and <code>pattern</code> consist of English letters.</li>
</ul>
</div>