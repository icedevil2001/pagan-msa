# Known issues #

## v.0.46 ##

<br>

<b>Problem</b>: On Windows, multi-threading and alignment anchoring may not work together.<br>
<br>
<b>Solution</b>: Either use without option <code>--use-anchors</code> (multi-threading without anchoring) or with options <code>--use-anchors --threads 1</code> (anchoring with a single thread).<br>
<br>
Any help in sorting this out is appreciated. A probable cause is in Boost::thread and using pipes to read stdout. Without much understanding of Cygwin and Windows in general, fixing this is tricky..<br>
<br>
<br>

<b>Problem</b>: On Windows, "speeds ups" requiring file operations may actually slow down the alignment.<br>
<br>
<b>Solution</b>: Consider not using option <code>--use-anchors</code> if calling Exonerate is very slow.<br>
<br>
(Observed on Windows running in a VM. This may not happen on native OS.)<br>
<br>
<br>