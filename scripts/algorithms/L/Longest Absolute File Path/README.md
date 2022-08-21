<h3 align="left"> 388. Longest Absolute File Path</h3>
<div><p>Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mdir.jpg" style="width: 681px; height: 322px;"></p>

<p>Here, we have <code>dir</code> as the only directory in the root. <code>dir</code> contains two subdirectories, <code>subdir1</code> and <code>subdir2</code>. <code>subdir1</code> contains a file <code>file1.ext</code> and subdirectory <code>subsubdir1</code>. <code>subdir2</code> contains a subdirectory <code>subsubdir2</code>, which contains a file <code>file2.ext</code>.</p>

<p>In text form, it looks like this (with ⟶ representing the tab character):</p>

<pre>dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
</pre>

<p>If we were to write this representation in code, it will look like this: <code>"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"</code>. Note that the <code>'\n'</code> and <code>'\t'</code> are the new-line and tab characters.</p>

<p>Every file and directory has a unique <strong>absolute path</strong> in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by <code>'/'s</code>. Using the above example, the <strong>absolute path</strong> to <code>file2.ext</code> is <code>"dir/subdir2/subsubdir2/file2.ext"</code>. Each directory name consists of letters, digits, and/or spaces. Each file name is of the form <code>name.extension</code>, where <code>name</code> and <code>extension</code> consist of letters, digits, and/or spaces.</p>

<p>Given a string <code>input</code> representing the file system in the explained format, return <em>the length of the <strong>longest absolute path</strong> to a <strong>file</strong> in the abstracted file system</em>. If there is no file in the system, return <code>0</code>.</p>

<p><strong>Note</strong> that the testcases are generated such that the file system is valid and no file or directory name has length 0.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/dir1.jpg" style="width: 401px; height: 202px;">
<pre><strong>Input:</strong> input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
<strong>Output:</strong> 20
<strong>Explanation:</strong> We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/dir2.jpg" style="width: 641px; height: 322px;">
<pre><strong>Input:</strong> input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
<strong>Output:</strong> 32
<strong>Explanation:</strong> We have two files:
"dir/subdir1/file1.ext" of length 21
"dir/subdir2/subsubdir2/file2.ext" of length 32.
We return 32 since it is the longest absolute path to a file.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> input = "a"
<strong>Output:</strong> 0
<strong>Explanation:</strong> We do not have any files, just a single directory named "a".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= input.length &lt;= 10<sup>4</sup></code></li>
	<li><code>input</code> may contain lowercase or uppercase English letters, a new line character <code>'\n'</code>, a tab character <code>'\t'</code>, a dot <code>'.'</code>, a space <code>' '</code>, and digits.</li>
	<li>All file and directory names have <strong>positive</strong> length.</li>
</ul>
</div>