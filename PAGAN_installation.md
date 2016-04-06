<img src='http://wiki.pagan-msa.googlecode.com/git/images/pagan_logo.png' width='400px'>

v. 0.46<br>
<br>
<br>

<hr />

<br>

<h1>Checking for PAGAN updates</h1>

PAGAN runs locally and does not contact or report to any external server. The only exception is the command <code>./pagan --version</code> that checks if a newer version of the program is available for download. The actual upgrade has to be performed manually.<br>
<br>
<br>

PAGAN is open-source software licensed under the GPL. The source code is provided at <a href='http://code.google.com/p/pagan-msa'>http://code.google.com/p/pagan-msa</a>. PAGAN is developed and most thoroughly tested on Ubuntu GNU/Linux system.<br>
<br>

<br>
<br>
<br>


<h1>Pre-compiled executables for Windows</h1>

The pre-compiled executables are available via the <a href='http://code.google.com/p/pagan-msa/downloads/list'>Downloads tab</a>, for Windows one is <a href='http://pagan-msa.googlecode.com/files/pagan.windows.20121025.zip'>here</a>.<br>
<br>
It is recommended to place the unpacked content of the zip file to the directory "Program Files". Here we assume that the file path to the directory "pagan" is <code>C:\Program Files\pagan</code>.<br>
<br>
For the ease of use, it is recommended to add the directory <code>pagan/bin</code> permanently to the system path. On Windows 7, this can be done through the following steps:<br>
<br>
<ul><li>open "Control Panel"<br>
</li><li>choose "System"<br>
</li><li>on the left panel, choose "Advanced system settings"<br>
</li><li>on the new window, click "Environment Variables"<br>
</li><li>find "Path" in the lower field, select it and click "Edit"<br>
</li><li>leave the existing content intact and add  <b><code>;C:\"Program Files"\pagan</code></b>  in the end of the field "Variable value"<br>
</li><li>click "OK" three times and close "Control Panel"</li></ul>

If you now open Command Prompt and write <code>pagan</code>, the program should run and show the options list.<br>
<br>
The executable has been compiled and tested on Windows 7 (32bit) system.<br>
<br>
<h2>Hints for using PAGAN on Windows</h2>

PAGAN is used through commands given in Command Prompt. For those not familiar with moving around files, the following workflow may be useful.<br>
<br>
<ul><li>open "Command Prompt" from "All Programs" -> "Accessories"<br>
</li><li>in Command Prompt, type commands<br>
<pre><code>mkdir analysis<br>
cd analysis<br>
explorer .<br>
</code></pre>
</li><li>drag and drop your alignment input file(s) to the Explorer window that was opened<br>
</li><li>in Command Prompt, run PAGAN as <code>pagan --seqfile=myfile [other options]</code>
</li><li>once finished, the result files will appear in the Explorer window</li></ul>

<br>

<h1>Pre-compiled executables for Mac OSX</h1>

The pre-compiled executables are available via the <a href='http://code.google.com/p/pagan-msa/downloads/list'>Downloads tab</a>, for OSX one is <a href='http://pagan-msa.googlecode.com/files/pagan.osx.20121025.tgz'>here</a>.<br>
<br>
The PAGAN executable for Mac has been compiled on OSX 10.8. The package contains the PAGAN executable as well as MAFFT, RAxML and Exonerate executables and the necessary files for those to work correctly.<br>
<br>
The PAGAN package file can be downloaded and unpacked using graphical software. With the command line, the same can be done with the commands:<br>
<pre><code>mkdir ~/programs<br>
cd ~/programs<br>
curl -O http://pagan-msa.googlecode.com/files/pagan.osx.20121025.tgz<br>
tar xvzf pagan.osx.20121025.tgz<br>
./pagan/bin/pagan<br>
</code></pre>
For the ease of use, it is recommended to add the directory <code>pagan/bin</code> to the system path or copy its content to a such directory (such as <code>~/bin</code> or <code>/usr/local/bin</code>). This can be done with commands similar to these:<br>
<pre><code>echo "export PATH=$PATH:/Users/$USER/programs/pagan/bin" &gt;&gt; ~/.bash_profile<br>
</code></pre>
or<br>
<pre><code>cp -R /Users/$USER/programs/pagan/bin/* ~/bin/<br>
</code></pre>
Note that if the executables are moved or copied, the directory structure (<code>bin/mafftlib</code>) and the location of library dependencies have to be retained.<br>
<br>
<br>

<h1>Pre-compiled executables for Linux</h1>

The pre-compiled executables are available via the <a href='http://code.google.com/p/pagan-msa/downloads/list'>Downloads tab</a>, for Linux one is <a href='http://pagan-msa.googlecode.com/files/pagan.linux.20121025.tgz'>here</a>.<br>
<br>
The PAGAN executable for Linux has been compiled on Red Hat 5.8 (64bit) and confirmed to work also on Ubuntu 12.04 and CentOS 6.0. The package  pagan.linux.xxxxxx.tgz contains the MAFFT, RAxML and Exonerate executables and the necessary files for these to work correctly<br>
<br>
Using the command line, the file can be downloaded and unpacked with the commands:<br>
<pre><code>mkdir ~/programs<br>
cd ~/programs<br>
wget http://pagan-msa.googlecode.com/files/pagan.linux.20121025.tgz<br>
tar xvzf pagan.linux.20121025.tgz<br>
./pagan/bin/pagan<br>
</code></pre>

For the ease of use, it is recommended to add the directory <code>pagan/bin</code> to the system path or copy its content to a such directory (such as <code>~/bin</code> or <code>/usr/local/bin</code>). This can be done with commands similar to these:<br>
<pre><code>echo "export PATH=$PATH:/home/$USER/programs/pagan/bin" &gt;&gt; ~/.bash_profile<br>
</code></pre>
or<br>
<pre><code>cp -R /home/$USER/programs/pagan/bin/* ~/bin/<br>
</code></pre>
Note that if the executables of the bundled version are moved or copied, the directory structure (<code>bin/lib</code>) and the location of library dependencies have to be retained.<br>
<br>
<br>
<br>

<h1>Installation of PAGAN from source code</h1>

<br>


<h2>Installation of Boost libraries</h2>

PAGAN requires <i>-dev versions</i> of three utility libraries from <a href='http://www.boost.org'>http://www.boost.org</a> that may not be included in standard OS installations. These libraries have to be installed <b>before</b> compiling the PAGAN source code. On Ubuntu, they can be installed using commands:<br>
<br>
<pre><code>apt-cache search libboost-program-options<br>
apt-cache search libboost-regex<br>
apt-cache search libboost-thread<br>
</code></pre>

(See which version number, ending with <code>-dev</code>, is provided and edit the command below.)<br>
<br>
<pre><code>sudo apt-get install libboost-program-options1.40-dev<br>
sudo apt-get install libboost-regex1.40-dev<br>
sudo apt-get install libboost-thread1.40-dev<br>
</code></pre>

If your distribution does not provide Boost libraries (highly  unlikely) or you are not allowed to install software on your system, you can download and install the necessary library from the Boost project repositories directly into your PAGAN source code directory. See the Advanced material below for details.<br>
<br>
On MacOSX, Boost can be installed with package management systems such as <a href='http://mxcl.github.com/homebrew/'>Homebrew</a>. On OSX 10.7, it can be installed with the following commands:<br>
<pre><code># uncheck below to install Homebrew<br>
# sudo /usr/bin/ruby -e "$(curl -fsSL https://raw.github.com/gist/323731)"<br>
sudo brew install boost<br>
</code></pre>
See <a href='http://mxcl.github.com/homebrew/'>http://mxcl.github.com/homebrew/</a> for further details.<br>
<br>
<br>
<br>

<h2>Download and installation of PAGAN using <code>git</code></h2>


The most recent version of the PAGAN source code is available from the git-repository and snapshots of this are downloadable as compressed tar-packages.<br>
The <code>git</code> software can be found at <a href='http://git-scm.com'>http://git-scm.com</a>. On Ubuntu, it can also be installed using command:<br>
<br>
<pre><code>sudo apt-get install git-core<br>
</code></pre>

Given that <code>git</code> is installed, the PAGAN source code can be downloaded and compiled using commands:<br>
<br>
<pre><code>git clone https://code.google.com/p/pagan-msa/<br>
cd pagan-msa/src<br>
make -f Makefile.no_Qt<br>
./pagan<br>
</code></pre>

Please note that the Google Code requires <code>git</code> version 1.6.6 or higher. You can check your program version with the command <code>git version</code>.<br>
<br>
Without <code>git</code>, the latest (but possibly not up-to-date) tar-packaged source code can be downloaded and compiled using commands:<br>
<br>
<pre><code>wget http://pagan-msa.googlecode.com/files/pagan.src.[latest].tgz<br>
tar xzf pagan.src.[latest].tgz<br>
cd pagan-msa/src<br>
make -f Makefile.no_Qt<br>
./pagan<br>
</code></pre>

<br>


<h2>Installation of Exonerate, MAFFT, RAxML</h2>

PAGAN can use MAFFT and RAxML to infer the guidetree and Exonerate to speed up the alignments. Those to work, you need to have MAFFT, RAxML and Exonerate installed and on the execution path.<br>
<br>
You can download the programs from <a href='http://www.ebi.ac.uk/~guy/exonerate/'>http://www.ebi.ac.uk/~guy/exonerate/</a> (Exonerate), <a href='http://mafft.cbrc.jp/alignment/software/source.html'>http://mafft.cbrc.jp/alignment/software/source.html</a> (MAFFT) and <a href='http://sco.h-its.org/exelixis/software.html'>http://sco.h-its.org/exelixis/software.html</a> (RAxML), and follow the instructions for their installation.<br>
On many popular Linux distributions these programs are available in the software repository and can be installed pre-compiled.<br>
On Ubuntu, that is done with the following command:<br>
<pre><code>sudo apt-get install exonerate<br>
sudo apt-get install mafft<br>
sudo apt-get install raxml<br>
</code></pre>

Because of dependencies to other programming libraries, the installation on MacOSX is easiest with a package management system such as <a href='http://mxcl.github.com/homebrew/'>Homebrew</a>. On OSX 10.7, Exonerate and MAFFT can be installed with the following commands:<br>
<pre><code># uncheck below to install Homebrew<br>
# sudo /usr/bin/ruby -e "$(curl -fsSL https://raw.github.com/gist/323731)"<br>
sudo brew install pkg-config<br>
sudo brew install exonerate<br>
sudo brew install mafft<br>
</code></pre>
See <a href='http://mxcl.github.com/homebrew/'>http://mxcl.github.com/homebrew/</a> for further details.<br>
<br>
<br>

<a href='PAGAN_installation#Introduction.md'>back to top</a>

<hr />


<br>

<h1>Advanced: installing <code>boost</code> from source code</h1>

If pre-packaged files are not available for your platform or you are not entitled to install packages and cannot persuade your system administrator to do that, the Boost libraries necessary for the compilation of the PAGAN source code can be installed using following commands:<br>
<br>
<pre><code># make a temporary directory<br>
mkdir ~/tmp_boost<br>
cd ~/tmp_boost<br>
<br>
# get the source code<br>
wget http://sourceforge.net/projects/boost/files/boost/1.44.0/boost_1_44_0.zip/download<br>
# OR (on OSX)<br>
# curl --location -o boost_1_44_0.zip http://sourceforge.net/projects/boost/files/boost/1.44.0/boost_1_44_0.zip/download<br>
unzip boost_1_44_0.zip<br>
cd boost_1_44_0<br>
<br>
# fix the permission<br>
chmod +x tools/jam/src/build.sh<br>
<br>
# compile and install<br>
sh ./bootstrap.sh --prefix=$PATH_TO_PAGAN_DIR/boost --with-libraries=program_options,regex,thread<br>
./bjam threading=multi link=static --prefix=$PATH_TO_PAGAN_DIR/boost install<br>
# on MacOSX, this may be preferred<br>
# ./bjam macosx-version=10.7 threading=multi link=static --prefix=$PATH_TO_PAGAN_DIR/boost install<br>
<br>
# clean up<br>
cd ../..<br>
rm -r ./tmp_boost<br>
</code></pre>

This compiles static versions of the boost libraries. The good thing is that those get statically linked to the executable and one does not need to worry about library paths. The bad thing is that the executable is rather big in size.