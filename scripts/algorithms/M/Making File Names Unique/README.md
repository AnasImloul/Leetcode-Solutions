<h3 align="left"> 1487. Making File Names Unique</h3>
<div><p>Given an array of strings <code>names</code> of size <code>n</code>. You will create <code>n</code> folders in your file system <strong>such that</strong>, at the <code>i<sup>th</sup></code> minute, you will create a folder with the name <code>names[i]</code>.</p>

<p>Since two files <strong>cannot</strong> have the same name, if you enter a folder name that was previously used, the system will have a suffix addition to its name in the form of <code>(k)</code>, where, <code>k</code> is the <strong>smallest positive integer</strong> such that the obtained name remains unique.</p>

<p>Return <em>an array of strings of length </em><code>n</code> where <code>ans[i]</code> is the actual name the system will assign to the <code>i<sup>th</sup></code> folder when you create it.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> names = ["pes","fifa","gta","pes(2019)"]
<strong>Output:</strong> ["pes","fifa","gta","pes(2019)"]
<strong>Explanation:</strong> Let's see how the file system creates folder names:
"pes" --&gt; not assigned before, remains "pes"
"fifa" --&gt; not assigned before, remains "fifa"
"gta" --&gt; not assigned before, remains "gta"
"pes(2019)" --&gt; not assigned before, remains "pes(2019)"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> names = ["gta","gta(1)","gta","avalon"]
<strong>Output:</strong> ["gta","gta(1)","gta(2)","avalon"]
<strong>Explanation:</strong> Let's see how the file system creates folder names:
"gta" --&gt; not assigned before, remains "gta"
"gta(1)" --&gt; not assigned before, remains "gta(1)"
"gta" --&gt; the name is reserved, system adds (k), since "gta(1)" is also reserved, systems put k = 2. it becomes "gta(2)"
"avalon" --&gt; not assigned before, remains "avalon"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
<strong>Output:</strong> ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
<strong>Explanation:</strong> When the last folder is created, the smallest positive valid k is 4, and it becomes "onepiece(4)".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= names.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= names[i].length &lt;= 20</code></li>
	<li><code>names[i]</code> consists of lowercase English letters, digits, and/or round brackets.</li>
</ul>
</div>