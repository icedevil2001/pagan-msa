<img src='http://wiki.pagan-msa.googlecode.com/git/images/pagan_logo.png' width='400px'>

v. 0.46<br>
<br>
<br>

<hr />

PAGAN is  a general-purpose method for the alignment of sequence graphs. PAGAN is based on the phylogeny-aware progressive alignment algorithm and uses graphs to describe the uncertainty in the presence of characters at certain sequence positions. However, graphs also allow describing the uncertainty in input sequences and modelling e.g. homopolymer errors in Roche 454 reads, or representing inferred ancestral sequences against which other sequences can then be aligned.<br>
<br>
The development of PAGAN started in <a href='http://www.ebi.ac.uk/goldman/'>Nick Goldman's group</a> at the EMBL-European Bioinfomatics Institute, UK, and continues now in <a href='http://blogs.helsinki.fi/sa-at-bi'>Ari Löytynoja's group</a> at the Institute of Biotechnology, University of Helsinki, Finland. PAGAN is still under development and will hopefully evolve to an easy-to-use, general-purpose method for phylogenetic sequence alignment.<br>
<br>
As the graph representation has features that make PAGAN especially powerful for phylogenetic placement of sequences into existing alignments, the functionality necessary for that has been implemented first. The method and its uses for alignment extension are described in this <a href='http://bioinformatics.oxfordjournals.org/content/28/13/1684.full'>paper</a> and its <a href='http://wiki.pagan-msa.googlecode.com/git/preprint/loytynoja_suppl.pdf'>supplementary material</a>.<br>
<br>
<hr />
<br>

<ul><li><b><a href='http://code.google.com/p/pagan-msa/wiki/PAGAN_installation?tm=6'>Installing PAGAN</a></b>
</li></ul><blockquote>Instructions to install and start using PAGAN on different operating systems.</blockquote>

<ul><li><b><a href='http://code.google.com/p/pagan-msa/wiki/PAGAN?tm=6#Using_PAGAN'>Using PAGAN</a></b>
</li></ul><blockquote>Instructions for the use of PAGAN with example commands and test data.</blockquote>

<ul><li><b><a href='http://code.google.com/p/pagan-msa/wiki/NewFeatures?tm=6'>New features</a></b>
</li></ul><blockquote>Brief description of the new features in the latest versions of the program</blockquote>

<ul><li><b><a href='http://code.google.com/p/pagan-msa/wiki/KnownIssues?tm=6'>Known issues</a></b>
</li></ul><blockquote>Some known problems with the current version of PAGAN</blockquote>

<ul><li><b><a href='http://code.google.com/p/pagan-msa/wiki/PreviouslyAsked?tm=6'>Previously asked questions</a></b>
</li></ul><blockquote>Some questions previously asked by other users -- check here before contacting me</blockquote>

<br>

<hr />

<br>

<h1>Using PAGAN</h1>

At the simplest, PAGAN can be run with command:<br>
<br>
<pre><code>pagan --seqfile input_file<br>
</code></pre>
where <code>input_file</code> contains sequences in FASTA format.<br>
<br>
See below for the description of the most central program options.<br>
<br>
<br>
<br>

<br>
<br>
<br>

<hr />

<br>

<h1>PAGAN command-line options</h1>


PAGAN is a command-line program. It can be used by (a) specifying a list of options (command-line arguments) when executing the program, or (b) creating a configuration file with the  options and specifying that when executing the program. The configuration file does not need to be created from scratch as PAGAN can output the options specified for an analysis in a file. This file can then be edited if necessary and specified as the configuration file for another analysis. Alternatively, the file can be considered as a record of a particular analysis with a full description of options and parameters used.<br>
<br>
A list of the most important program options is outputted if no arguments are provided:<br>
<br>
<pre><code>./pagan<br>
</code></pre>

and a more complete list is given with the option <code>--help</code>:<br>
<br>
<pre><code>./pagan --help<br>
</code></pre>

In general, the option names start with <code>--</code> and the option name and value (if any) are separated by a space. The configuration file makes an exception and can be specified without the option name:<br>
<br>
<pre><code>./pagan option_file<br>
</code></pre>

Also this one can be given in the standard format and the following command is equivalent:<br>
<br>
<pre><code>./pagan --config-file option_file<br>
</code></pre>


<br>

<a href='PAGAN#Using_PAGAN.md'>back to top</a>

<hr />

<br>

<h1>Phylogenetic multiple alignment</h1>

PAGAN is based on a progressive algorithm that aligns sequences according to a guide tree. It can compute a guide tree using external programs (MAFFT and RAxML) but also allows the user to provide a <b>rooted</b> binary tree relating the sequences. The leaf names in the tree and the sequence names (until the first space) in the sequence file have to match exactly. Alignment is only performed for the parts of the guide phylogeny that have sequences associated; the unnecessary branches and sequences are pruned/dropped out.<br>
<br>
If MAFFT and RAxML are available on the system (and can be called with commands <code>mafft</code> and <code>raxml</code>), the minimal command to perform the alignment is:<br>
<br>
<pre><code>./pagan --seqfile sequence_file <br>
</code></pre>


Using a user-specified tree, the minimal command to perform the alignment is:<br>
<br>
<pre><code>./pagan --seqfile sequence_file --treefile tree_file <br>
</code></pre>

The resulting alignment will be written in file <code>outfile.fas</code>. If you want to use another file name, you can specify that with option <code>--outfile</code>:<br>
<br>
<pre><code>./pagan --seqfile sequence_file [--treefile tree_file] --outfile another_name<br>
</code></pre>

PAGAN will automatically add a suffix for the corresponding output format (by default, <code>.fas</code> for FASTA).<br>
<br>
<h2>Input and output formats</h2>

The sequence input file has to be in FASTA format and the guide tree in Newick tree format, with branch lengths as substitutions per site. By default, the resulting alignment will be written in FASTA format. Other output formats (<code>nexus</code>, <code>paml</code>, <code>phylipi</code>, <code>phylips</code> or <code>raxml</code>) can specified with option <code>--outformat format_name</code>. With option <code>--xml</code>, PAGAN writes an additional file, containing both the alignment and the guide phylogeny, in the XML-based <a href='http://www.ebi.ac.uk/goldman-srv/hsaml'>HSAML format</a>.<br>
<br>
PAGAN writes several temporary files to communicate with the helper tools. By default, these files are written to <code>/tmp</code> directory (or current directory if <code>/tmp</code> does not exist) and deleted afterwards.  The directory can be changed with option <code>--temp-folder directory_path</code> and the removal of the files prevented with option <code>--keep-temp-files</code>.<br>
<br>
<h2>Alignment anchoring</h2>

PAGAN can significantly speed up some alignments by anchoring the alignment with Exonerate (called with command <code>exonerate</code>).  This feature is still experimental and has to defined separately with option <code>--use-anchors</code>, e.g. as:<br>
<br>
<pre><code>./pagan --seqfile sequence_file [--treefile tree_file] --outfile another_name --use-anchors<br>
</code></pre>


<h2>Codon alignment and translated alignment</h2>

PAGAN supports the alignment of nucleotide, amino-acid and codon sequences as well as translated alignment of nucleotide sequences. The type of data is detected automatically and either DNA or protein model is used. With option <code>--codons</code>, PAGAN can align protein-coding DNA sequences using the codon substitution model. Alternatively, with option <code>--translate</code>, PAGAN translates the DNA sequences to proteins, aligns them as proteins and writes the resulting alignment as proteins and back-translated DNA. Codon and translated alignment are performed in the first reading frame and no frame correction is performed.<br>
<br>
<br>
<h2>An example analysis with PAGAN</h2>

As an example of combining several options, the following command:<br>
<br>
<pre><code>./pagan --seqfile cDNA_unaligned.fas --outfile cDNA_aligned  --outformat paml --use-anchors \<br>
 --codons  --config-log-file cDNA_alignment.cfg<br>
</code></pre>

would (i) read in protein-coding DNA sequences from the file <code>cDNA_unaligned.fas</code>, (ii) translate the sequences to proteins and perform an initial alignment with MAFFT, (iii) infer a guidetree for this protein alignment with RAxML, (iv) treating the sequences as codon sequences, perform the PAGAN alignment using anchors inferred with Exonerate on protein-translated sequences, and (v) write the output alignment to the file <code>cDNA_aligned.phy</code> in a format compatible with PAML and the RAxML-estimated guidetree to the file <code>cDNA_aligned.tre</code> in Newick format. The last option tells PAGAN to write the options used to the file <code>cDNA_alignment.cfg</code>: this file can be stored as a record of the analysis performed but it also fully specifies the options for PAGAN and allows repeating the same analysis with the command:<br>
<br>
<pre><code>./pagan cDNA_alignment.cfg<br>
</code></pre>


<br>

<a href='PAGAN#Using_PAGAN.md'>back to top</a>

<hr />

<br>

<h1>Phylogenetic placement of sequences into an existing alignment</h1>

There are many methods to add sequences to existing alignments. However, most of these ignore the phylogenetic relationships among the data and simply place the new sequences in the bottom of the alignment. The idea of phylogenetic placement is to extend existing alignments by aligning the new sequences to their true evolutionary positions in the reference alignment. This ensures that the new sequences are compared to the closest possible reference sequence and the alignment created, including the gaps opened for insertions and deletions, is as accurate as possible.<br>
<br>
PAGAN can reconstruct ancestral sequence history for a reference alignment related by a phylogeny. Sequences can then be added to this reference alignment by aligning the new sequences against terminal (extant reference sequences) or internal nodes (reconstructed ancestral sequences) and making room for the added sequences in their correct evolutionary positions among the reference sequences; the addition of new sequences does not affect the relative alignment of original sequences.<br>
<br>
The current version of PAGAN is primarily aimed for guided placement of sequences, i.e. addition of sequences for which the (rough) phylogenetic location is known. The program includes support for unguided placement and can exhaustively search for the best nodes to place the new sequences. However, the latter is still experimental and, if target nodes for guided placement are not specified and exhaustive search is not selected, PAGAN will by default add the sequences at the root of the phylogeny.<br>
<br>
Originally the target application for the phylogenetic placement was in the analysis of short NGS reads but the same principles also work for full-length DNA sequences and for amino-acid sequences.<br>
<br>
The minimal command to perform the sequence placement is:<br>
<br>
<pre><code>./pagan --ref-seqfile ref_alignment_file --ref-treefile ref_tree_file --queryfile query_sequence_file<br>
</code></pre>

The reference alignment has to be in FASTA format and the reference tree in Newick or Newick eXtended (NHX) format; the query sequences that will be added in the reference alignment can be either in FASTA or FASTQ format. If the reference alignment consists of one sequence only, the reference guide tree is not required. Again, you can define your own output file with option <code>--outfile</code>.<br>
<br>
<br>

<h2>Assignment of queries to specific nodes</h2>

If the phylogenetic position of the sequences to be added is known (e.g. the species in question is an outgroup for the clade X), this information can be provided for the placement. Furthermore, one can name multiple alternative positions for the sequences (because the precise position is not known or the reference contains paralogous genes and the copies which the sequences come from are not known) and PAGAN will choose the one where the sequences matches the best. Sequences are assigned to a specific node or a set of nodes using the NHX tree format with an additional tag <code>TID</code>. The tag identifier can be any string, in the example below we use number <code>001</code>. One can use any number/combination of tags as long as each node and each sequence has at most one tag.<br>
<br>
As an example, let's assume<br>
<br>
a reference alignment:<br>
<br>
<pre><code>&gt;A<br>
AGCGATTG<br>
&gt;B<br>
AACGATCG<br>
&gt;C<br>
TGCGGTCC<br>
</code></pre>

and a read that we want to add in FASTA:<br>
<br>
<pre><code>&gt;D TID=001<br>
AGCGATCG<br>
</code></pre>

or in FASTQ format:<br>
<br>
<pre><code>@read_D_0001@3@15@13524@18140#0/1 TID=001<br>
AGCGATCG<br>
+<br>
CCCCCCCC<br>
</code></pre>

The placement of the read in the reference alignment depends on the format of the reference tree:<br>
<br>
a phylogeny in plain Newick format adds the read at the root of the tree:<br>
<pre><code>((A:0.1,B:0.1):0.05,C:0.15);<br>
</code></pre>

a phylogeny in NHX format with one matching label adds the read to that node:<br>
<pre><code>((A:0.1,B:0.1):0.05[&amp;&amp;NHX:TID=001],C:0.15);<br>
</code></pre>

a phylogeny in NHX format with several matching labels finds the best node and adds the read to that:<br>
<pre><code>((A:0.1,B:0.1):0.05[&amp;&amp;NHX:TID=001],C:0.15):0[&amp;&amp;NHX:TID=001];<br>
</code></pre>

With ArchaeopteryxPE, the target nodes are shown with yellow dots and the three tree files look like this:<br>
<br>
<img src='http://wiki.pagan-msa.googlecode.com/git/images/tree1.png' width='200px'> <img src='http://wiki.pagan-msa.googlecode.com/git/images/tree2.png' width='200px'> <img src='http://wiki.pagan-msa.googlecode.com/git/images/tree3.png' width='200px'>

In all cases, options <code>--test-every-internal-node</code> and <code>--test-every-node</code> override the placement information given in the guide tree and exhaustively search the best placement.<br>
<br>
<br>

<h2>Use of Archaeopteryx-PAGAN-Edition</h2>

The NHX phylogeny format used for the tagging of target nodes for guided placement is unique for PAGAN. To facilitate the preparation and visualisation of the reference phylogenies, we have modified Archaeopteryx, the superb phylogeny visualisation program by Christian M Zmasek, to understand the PAGAN-specific tags and allow for their editing. The original Archaeopteryx program and documentation for its use can be found at <a href='http://phylosoft.org/archaeopteryx/'>http://phylosoft.org/archaeopteryx/</a>.<br>
<br>
The Archaeopteryx-PAGAN-Edition (here abbreviated as ArchaeopteryxPE) has one additional feature compared to the original program: the program can read, display, edit and write NHX files containing <code>TID=&lt;string&gt;</code> tags used for guided sequence placement with PAGAN. For any other purposes of tree display or editing you should use an up-to-date version of the original Archaeopteryx program. ArchaeopteryxPE is available as <a href='http://pagan-msa.googlecode.com/files/archaeopteryxPE.jar'>Java jar-file</a> at the <a href='http://code.google.com/p/pagan-msa/downloads'>download page</a> and can then be started with the command:<br>
<br>
<pre><code>java -jar archaeopteryxPE.jar [reference.nhx]<br>
</code></pre>

where the optional argument 'reference.nhx' specifies a phylogeny file.<br>
(An example of a <a href='http://pagan-msa.googlecode.com/files/reference.nhx'>valid tree file</a> is available at the <a href='http://code.google.com/p/pagan-msa/downloads'>download page</a>.) This command assumes that the ArchaeopteryxPE program is located in the same directory; if not, type<br>
<br>
<pre><code>java -jar /path/to/dir/with/archaeopteryxPE.jar reference.nhx<br>
</code></pre>

The source files modified to provide the necessary functionality are included in a <a href='http://pagan-msa.googlecode.com/files/archaeopteryxPE.modified_files.src.tgz'>separate file</a>. This is provided to comply with the GPL and is not needed by a typical user.<br>
<br>
The tree in the example file provided contains two types of NHX tags, <code>D=Y</code> and <code>TID=0[12]</code>. The red dots indicate duplication nodes (<code>D=Y</code>) and yellow dots the PAGAN target nodes (<code>TID=01</code> or <code>TID=02</code>). If a yellow node is clicked, a panel with the node data, including the PAGAN TID, is opened. To edit an existing TID tag or add a new tag at another node, the node has to be right-clicked and then "Edit Node Data" selected (or "Edit Node Data" selected at the "Click on Node to:" drop-down menu on the left and then the node clicked). This will open an edit panel with the PAGAN TID field in the bottom. The text-insert mode can be activated by clicking (repeatedly) the text field on the right side of the page icon. When saving the tree file, the NHX format can be selected from the file format drop-down menu.<br>
<br>
<br>
<br>

<h2>Examples of guided placement</h2>

The PAGAN download files contain example datasets for guided placement of protein sequences (full length and fragments) and NGS reads. The datasets can found in directories <a href='http://code.google.com/p/pagan-msa/source/browse/#git%2Fexamples%2Fprotein_placement'>`examples/protein_placement`</a> and <a href='http://code.google.com/p/pagan-msa/source/browse/#git%2Fexamples%2Fngs_placement'>`examples/ngs_placement`</a>.<br>
<br>
The idea of guided placement is to extend existing alignments with new sequences for which the (rough) phylogenetic location is known. The situation may be complicated by paralogous genes and uncertainty of the right target for the new sequences. For such cases, PAGAN allows indicating several potential targets and then chooses the best location by aligning the query sequences to each specified target.<br>
<br>
The examples are based on simulated data. In these examples, we have reference alignments that include gene sequences from several mammals; the hypothetical gene has duplicated first in the ancestor of primates and rodents and then again in the ancestor of rodents. Our new sequences come from a primitive primate, believed to belong phylogenetically between tarsier and lemur, and a rodent, belonging between guinea pig and ground squirrel. Because of the gene duplications, the primate and rodent sequences have two and three potential target locations, respectively, in the phylogeny. These are indicated in the reference phylogenies using special TID tags. The phylogenies and the target locations for guided placement can be viewed and edited with the <a href='http://pagan-msa.googlecode.com/files/archaeopteryxPE.jar'>ArchaeopteryxPE software</a> available on the <a href='http://code.google.com/p/pagan-msa/downloads'>PAGAN download site</a>. ArchaeopteryxPE indicates the duplication nodes with red dots and the TID target nodes with yellow dots and the guide phylogeny looks like this:<br>
<br>
<img src='http://wiki.pagan-msa.googlecode.com/git/images/guide_tree.png' width='600px'>

When sequences are placed with PAGAN, it first tries placing each query sequence to every matching target node and chooses the best node. If several target nodes score equally well, the sequence is assigned to each one of them. PAGAN then starts aligning the sequences to targets, adding several query sequences to the same target using a progressive approach. The complete new subtree is then inserted back to the reference alignment, adding space for the new insertions if necessary. Importantly, the relative alignment of existing reference sequences is not changed.<br>
<br>
The examples demonstrate that the selection of the target node for each query sequence is not straightforward. Long sequences are placed correctly but shorter ones may be placed to a wrong node. Errors are also more likely between closely-related paralogs than between distant ones.<br>
<br>
<br>

<h3>Example of guided placement of protein sequences</h3>

The following files are included in directory <a href='http://code.google.com/p/pagan-msa/source/browse/#git%2Fexamples%2Fprotein_placement'>`examples/protein_placement`</a>:<br>
<br>
<ul><li><code>reference_aa.fas</code>   : simulated reference alignment.<br>
</li><li><code>reference_tree.nhx</code> : reference phylogeny with some nodes tagged for placement.<br>
</li><li><code>input_aa_full.fas</code>  : simulated amino-acid sequences.<br>
</li><li><code>input_aa_frags.fas</code> : a subset of the one above, broken into fragments.</li></ul>

The data can be analysed using the following commands:<br>
<br>
<pre><code>pagan --ref-seqfile reference_aa.fas --ref-treefile reference_tree.nhx \<br>
 --queryfile input_aa_full.fas --outfile aa_full_alignment<br>
<br>
pagan --ref-seqfile reference_aa.fas --ref-treefile reference_tree.nhx \<br>
 --queryfile input_aa_frags.fas --outfile aa_frags_alignment<br>
</code></pre>

The resulting alignments will be written to files <code>aa_[full|frags]_alignment.fas</code>.<br>
<br>
The reference alignment used for the analysis, the true simulated alignment and the resulting PAGAN alignments look like this (click to see larger images):<br>
<br>
<table><thead><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/reference_aa.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/reference_aa_m.png' /></a></th></thead><tbody>
<tr><td> Reference alignment                                                                                                                                           </td></tr>
<tr><td><a href='http://wiki.pagan-msa.googlecode.com/git/images/aa_true_alignment.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/aa_true_alignment_m.png' /></a></td></tr>
<tr><td> True simulated alignment                                                                                                                                      </td></tr></tbody></table>

<table><thead><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/aa_full_alignment.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/aa_full_alignment_m.png' /></a></th></thead><tbody>
<tr><td> Placement of full sequences                                                                                                                                             </td></tr>
<tr><td><a href='http://wiki.pagan-msa.googlecode.com/git/images/aa_frags_alignment.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/aa_frags_alignment_m.png' /></a></td></tr>
<tr><td> Placement of sequence fragments                                                                                                                                         </td></tr></tbody></table>

The different background colours for the placed sequences indicate their different origin.<br>
<br>
<br>

<h3>Example of guided placement of NGS reads</h3>

The following files are included in directory <a href='http://code.google.com/p/pagan-msa/source/browse/#git%2Fexamples%2Fngs_placement'>`examples/ngs_placement`</a>:<br>
<br>
<ul><li><code>reference_codon.fas</code> : simulated reference alignment.<br>
</li><li><code>reference_tree.nhx</code>  : reference phylogeny with some nodes tagged for placement.<br>
</li><li><code>input_ngs.fastq</code>     : simulated Illumina reads.<br>
</li><li><code>input_ngs_primates.fastq</code> : a subset of the one above.</li></ul>

The data can be analysed using the following command:<br>
<br>
<pre><code>pagan --ref-seqfile reference_codon.fas --ref-treefile reference_tree.nhx \<br>
 --queryfile input_ngs.fastq --outfile read_alignment<br>
</code></pre>

The resulting alignments will be written to file read_alignment.fas.<br>
<br>
If we add the option <code>--config-log-file</code>:<br>
<br>
<pre><code>pagan --ref-seqfile reference_codon.fas --ref-treefile reference_tree.nhx \<br>
--queryfile input_ngs.fastq --outfile read_alignment --config-log-file simple.cfg<br>
</code></pre>

the arguments used for the analysis will be written to the file <code>simple.cfg</code>. This file works as a log file of the specific settings used for the analysis and allows repeating the same analysis with the command:<br>
<br>
<code>pagan simple.cfg</code>  (or <code>pagan --config-file simple.cfg</code>)<br>
<br>
The use of config files simplifies complex commands. For example, the following:<br>
<br>
<pre><code>pagan --ref-seqfile reference_codon.fas --ref-treefile reference_tree.nhx \<br>
--queryfile input_ngs.fastq --trim-read-ends --build-contigs --use-consensus \<br>
--consensus-minimum 3 --show-contig-ancestor --outfile read_alignment \<br>
--config-log-file contigs.cfg<br>
</code></pre>

specifies config file <code>contigs.cfg</code>. As the arguments given on the command line override those given in a config file, the following command repeats a similar analysis for another data set.<br>
<br>
<pre><code>pagan contigs.cfg --queryfile input_ngs_primates.fastq --outfile primate_alignment<br>
</code></pre>

The reference alignment used for the analysis, the true simulated alignment and the resulting PAGAN alignments look like this:<br>
<br>
<table><thead><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/reference_codon.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/reference_codon_m.png' /></a></th></thead><tbody>
<tr><td> Reference alignment                                                                                                                                                 </td></tr>
<tr><td><a href='http://wiki.pagan-msa.googlecode.com/git/images/true_alignment.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/true_alignment_m.png' /></a>  </td></tr>
<tr><td> True simulated alignment                                                                                                                                            </td></tr></tbody></table>

<table><thead><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/read_alignment.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/read_alignment_m.png' /></a></th></thead><tbody>
<tr><td> Placement of all reads                                                                                                                                            </td></tr>
<tr><td><a href='http://wiki.pagan-msa.googlecode.com/git/images/primate_alignment.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/primate_alignment_m.png' /></a></td></tr>
<tr><td> Placement of primate reads                                                                                                                                        </td></tr></tbody></table>

The different background colours for the placed sequences indicate their different origin.<br>
<br>
You may check the content of files <code>read_alignment_contigs.fas</code> and<br>
<code>primate_alignment_contigs.fas</code>:<br>
<br>
<table><thead><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/read_alignment_contigs.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/read_alignment_contigs_s.png' /></a></th><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/primate_alignment_contigs.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/primate_alignment_contigs_s.png' /></a></th></thead><tbody>
<tr><td> Contigs from all reads                                                                                                                                                            </td><td> Contigs from primate reads                                                                                                                                                              </td></tr></tbody></table>

The quality of contigs is expected to improve with a higher sequencing coverage.<br>
<br>
See <code>pagan --help</code> and the program documentation for additional options.<br>
<br>
<br>

<h2>Unguided placement -- or metagenomic analyses using PAGAN</h2>

If no target nodes (TID tags) are specified in the reference phylogeny, PAGAN will by default add the sequences in the bottom of the alignment by aligning them against the root node. This can be overridden with options <code>--test-every-internal-node</code> and <code>--test-every-node</code> that exhaustively search through either internal nodes or all nodes (including leaf nodes) and add the sequence at the node where it matches the best. This allows using PAGAN for metagenomic analyses of sequences of unknown origin.<br>
<br>
Exhaustive search using PAGAN's exact alignment can be very slow. To speed up the search of the optimal placement node, PAGAN can use Guy Slater's <a href='http://www.ebi.ac.uk/~guy/exonerate'>Exonerate</a>; Exonerate is not provided by the PAGAN package and has to be installed separately and be on the system's execution path ($PATH). See <a href='http://code.google.com/p/pagan-msa/wiki/PAGAN?tm=6#Installation_of_Exonerate'>the instruction</a> above for the details.<br>
<br>
<br>
The default combination of settings is chosen with option <code>--fast-placement</code> and typically one would also use option <code>--test-every-internal-node</code> or <code>--test-every-node</code>, or have a guide tree with tagged nodes for placement. With this option, PAGAN runs Exonerate local alignment against the chosen nodes (all/all internal/all tagged) and keep the best of them; it would then run Exonerate gapped alignment against those nodes and choose the best for the placement.<br>
<br>
With other options, one can choose to perform just a local or gapped alignment with Exonerate, and change the number of nodes kept after each round. The number of nodes kept is based either on the score relative to the best score, or a fixed number of best-ranking nodes. If more than one node is returned by Exonerate, PAGAN will perform alignments against those and choose the best scoring one for the placement.<br>
<br>
<br>

<h3>Example of unguided placement of NGS reads</h3>

The following files are included in directory <a href='http://code.google.com/p/pagan-msa/source/browse/#git%2Fexamples%2Fngs_placement'>`examples/ngs_placement`</a>:<br>
<br>
<ul><li><code>reference_codon.fas</code> : simulated reference alignment.<br>
</li><li><code>reference_tree.nhx</code>  : reference phylogeny (with some nodes tagged for placement).<br>
</li><li><code>input_ngs.fastq</code>     : simulated Illumina reads.<br>
</li><li><code>input_ngs_primates.fastq</code> : a subset of the one above.</li></ul>

These files are primarily meant to demonstrate <b>guided</b> placement but can equally well be used for <b>unguided</b> placement. As the unguided placement can be very slow, we use here the Exonerate speed-up and assume that the Exonerate software is installed on the system as explained above. The PAGAN placement of query sequences is approximate and is only performed to allow for the accurate alignment of the data (e.g. for downstream analyses to build longer contigs of the overlapping sequences). If the aim is to infer the phylogenetic origin of the query sequences, one should re-analyse the alignments with an appropriate program.<br>
<br>
If one wants to use the speed-ups for the placement search but restrict the placement to the tagged nodes, the data can be analysed using the following command:<br>
<br>
<pre><code>pagan --ref-seqfile reference_codon.fas --ref-treefile reference_tree.nhx \<br>
 --queryfile input_ngs_primates.fastq --outfile read_alignment --fast-placement<br>
</code></pre>

If one does not want to restrict the placement to certain nodes or the reference tree does not contain any placement tags, one can use one of the following commands:<br>
<br>
<pre><code>pagan --ref-seqfile reference_codon.fas --ref-treefile reference_tree.nhx \<br>
 --queryfile input_ngs_primates.fastq --outfile read_alignment --fast-placement \<br>
--test-every-internal-node<br>
</code></pre>
or<br>
<pre><code>pagan --ref-seqfile reference_codon.fas --ref-treefile reference_tree.nhx \<br>
 --queryfile input_ngs_primates.fastq --outfile read_alignment --fast-placement \<br>
--test-every-node<br>
</code></pre>

As could be guessed, the first command only considers placement at the internal nodes of the reference phylogeny (<code>--test-every-internal-node</code>) whereas the second one considers all nodes (<code>--test-every-node</code>) and can place the reads also at the tip/leaf nodes.<br>
<br>
PAGAN makes the alignment in two phases: it first finds the best phylogenetic location for each read and, once that is finished, it then aligns the reads to the locations chosen. The progressive approach of the latter allows correctly taking into account the insertions shared by the query reads and not present in the reference alignment. PAGAN aligns and outputs full sequences but it may sometimes discard complete reads if no good placement is found (by Exonerate) or the resulting alignments (by PAGAN) looks poor. A placement for some reads discarded by Exonerate may be found with PAGAN's exhaustive search that is selected with option <code>--exhaustive-placement</code>; the threshold for the read rejection at the later stages can be adjusted with options <code>--overlap-minimum</code>, <code>--overlap-identity</code> and <code>--overlap-identical-minimum</code>. See <code>pagan --help</code> for the default values.<br>
<br>
Although poorly matching reads may be discarded, PAGAN does not otherwise delete sites of the query reads. If the FASTQ trimming is used, low-quality reads may be truncated from the ends.<br>
<br>
One should also note that PAGAN can place one query sequence to multiple locations if they score equally well. This makes sense in some analyses but may cause problems in others. This behaviour can be disabled with option <code>--one-placement-only</code>. All these options together give the following command:<br>
<br>
<pre><code>pagan --ref-seqfile reference_codon.fas --ref-treefile reference_tree.nhx \<br>
 --queryfile input_ngs_primates.fastq --outfile read_alignment --fast-placement \<br>
--test-every-node --exhaustive-placement --one-placement-only<br>
</code></pre>

<br>

<h3>Experimental options for metagenomic analysis of large data sets</h3>

When finding placement for the queries, PAGAN communicates with Exonerate through temporary files. Typically, the placement is performed one query at time and requires writing files for the query sequence and for the target sequences; this is repeated twice, first with a rough and then with a more thorough alignment. For a large number of queries, this requires lots reading and writing and there is also significant overhead in launching Exonerate multiple times.<br>
<br>
PAGAN now includes an experimental feature to quickly assign queries to targets using approximate ungapped alignments only. In practice,  the analysis starts with the placement of all queries and Exonerate is run only once (albeit this can be a relatively long run). The new option for this is called <code>--very-fast-placement</code>.<br>
<br>
This options was tested on the alignment of <a href='http://www.cs.utexas.edu/users/phylo/software/sepp/submission/'>synthetic metagenomic data from Mirarab et al</a>. These data sets consist of a 500-taxon reference tree and 5000 query sequences from related species. The command used was:<br>
<br>
<pre><code>pagan --ref-seqfile reference_alignment.fas --ref-treefile reference_tree.nh \<br>
--queryfile fragments.fas --test-every-node --very-fast-placement <br>
</code></pre>

PAGAN performed very well in the alignment of closely-related queries and aligned nearly all of them with high accuracy. In the alignment of more diverged sequences, its alignment accuracy was still high but the heuristic  placement approach failed to find targets for a large proportion of queries.<br>
<br>
<br>

<h2>Pair-end reads and 454/PacBio data</h2>

For the alignment of NGS reads, additional options <code>--pair-end</code>, <code>--454</code> and <code>--pacbio</code> are useful. The first one merges paired reads into one (separated by a spacer) before the alignment and the second and third model the ambiguous length of mononucleotide runs and the high frequency of insertion-deletions in data coming from Roche 454 and PacBio SMRT platforms. The pairing of pair-end reads assumes that the reads have identical names (until the first space) with the exception that the left read ends with <code>/1</code> and the right read with <code>/2</code>. In the resulting alignment, the paired sequence will have suffix <code>/p12</code>.<br>
<br>
<br>

<h2>Overlapping pair-end reads</h2>

The length and overall quality of NGS data can be improved by using such a short fragment length that the reads starting from each end of the fragment overlap in the middle. PAGAN allows merging such reads and handling them as one sequence. Merging is done using option <code>--overlap-pair-end</code>, the reads successfully merged having suffix <code>/m12</code> in the resulting alignment.<br>
<br>
The merging requires significant overlap between the two reads in their pairwise alignment (performed without masking). Options <code>--overlap-minimum</code> and <code>--overlap-identity</code> can be used to change the minimum length and base identity of this overlap. Shorter overlaps that show perfect base identity are also accepted; the minimum length of this can be changed with option <code>--overlap-identical-minimum</code>. The merged reads can be outputted in FASTQ format using option <code>--overlap-merge-file</code>.<br>
PAGAN can also be used just to merge the overlapping reads:<br>
<br>
<pre><code>./pagan --overlap-merge-only --queryfile reads_file --overlap-merge-file merge_file<br>
</code></pre>

<br>

<h2>Consensus ancestor reconstruction and phylogenetic contig assembly</h2>

PAGAN's graph reconstruction is based on maximum parsimony. In NGS read placement, the overlapping regions of reads placed to a specific target node are expected to be identical and any differences observed are (with the exception heterozygosity that we ignore) some sort of errors. For the placement of DNA sequences, PAGAN offers an alternative approach to reconstruct ancestor graphs based on majority consensus. This is selected with option <code>--use-consensus</code>.<br>
<br>
Using a similar majority consensus approach, PAGAN can combine reads placed to a specific target into longer contigs. This is done with option <code>--build-contigs</code>; the minimum number of reads supporting a site in the contig can be changed with option <code>--consensus-minimum</code>. The contigs, with the reads supporting them, are written to a file named <code>*_contigs.fas</code>.<br>
<br>
By default, the disconnected contigs are bridged with <code>n</code>'s, estimating the size of the contig gap from the outgroup ancestral sequence. With option <code>--show-contig-ancestor</code> they can be bridged using the actual ancestral sequences, the contig gaps indicated with lower case characters.<br>
<br>
<br>

<h2>Typical analysis of NGS data</h2>

A typical command to perform the placement of NGS reads could be:<br>
<br>
<pre><code>./pagan --ref-seqfile ref_alignment_file --ref-treefile ref_tree_file --queryfile reads_file \<br>
    [--trim-read-ends] [--pair-end] [--overlap-pair-end] [--454] <br>
</code></pre>

where the optional (and some mutually exclusive) options are in square brackets.<br>
<br>
<br>
Depending on the output, the thresholds for masking and trimming can be adjusted using the relevant options explained below. The effect of trimming is obvious from the output; the bases written in lower case in the output were masked and considered as N's during the alignment. A sequence of N's matches any sequence and gives rubbish alignments; if that happens, you may need to raise the masking threshold or lower the trimming thresholds.<br>
<br>
<br>
<br>

<a href='PAGAN#Using_PAGAN.md'>back to top</a>

<hr />

<br>

<h1>Pileup alignment without a guide tree</h1>

PAGAN can make "pileup" alignments by adding the sequences in the order their appear in the input file. This is not recommended for distantly-related sequences but can be useful for highly similar sequences that require alignment. This may be relevant e.g. in the analysis of overlapping noisy reads from the same locus; if the reads have been generated on Roche 454 or Ion Torrent platform, PAGAN's ability to model the homopolymer errors is especially useful.<br>
<br>
Like in any alignment also in a pileup alignment the consenus sequence (the alignment of sequences included so far) and the next sequence to be added should overlap. PAGAN can include sequences that do not overlap but the region in between has to be bridged by other sequences and thus the order of adding the sequences can be important. If the sequences are from the same species, the option to reconstruct the consensus sequence can also be useful.<br>
<br>
The pileup alignment is done by selecting option <code>--pileup-alignment</code> and defining the input file with <code>--queryfile query_sequence_file</code>.  Typically one would also add option <code>--use-consensus</code> to specify that the character states are based on consensus, not the last-added and possibly incorrect sequence (e.g. due to contamination of the data), and to output the final consensus sequence. If the sequences are from Roche 454 or Pacific Biosciences platforms, one may also add option <code>--454</code> or <code>--pacbio</code> to tune the parameters specifically for those instruments; many other options are naturally compatible with the pileup alignment, too.<br>
<br>
The many options needed for this can be defined in a config file. Assuming that the file <code>454.cfg</code> contains the following:<br>
<br>
<pre><code>454 = 1<br>
pileup-alignment = 1<br>
use-consensus = 1<br>
build-contigs = 1<br>
no-terminal-edges = 1<br>
silent = 1<br>
</code></pre>

the pile-up alignment for a set of 454 data can then be generated with the command:<br>
<br>
<pre><code>./pagan 454.cfg --queryfile reads_file --outfile output_file<br>
</code></pre>


<br>

<h3>Example of pileup alignment of 454 reads</h3>

The PAGAN download files contain an example dataset for pileup alignment of overlapping 454 reads. The dataset can found in directory <a href='http://code.google.com/p/pagan-msa/source/browse/#git%2Fexamples%2F454_pileup'>`examples/454_pileup`</a>. The following file is included:<br>
<br>
<ul><li>454_reads.fas : simulated overlapping 454 reads</li></ul>

The data can be analysed using the following command:<br>
<br>
<pre><code>pagan --pileup-alignment --use-consensus --454 --queryfile 454_reads.fas --outfile 454_reads_pagan<br>
</code></pre>

The resulting alignment will be written to file 454_reads_pagan.fas.<br>
<br>
Using the config file from above, a similar analysis could be performed with the command:<br>
<br>
<pre><code>pagan 454.cfg --queryfile 454_reads.fas --outfile 454_reads_pagan<br>
</code></pre>

The modelling of homopolymer error has an impact even in the alignment of relatively clean data:<br>
<br>
<table><thead><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_pagan.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_pagan_m.png' /></a></th></thead><tbody>
<tr><td> PAGAN alignment                                                                                                                                                     </td></tr></tbody></table>

<table><thead><th><a href='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_mafft.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_mafft_m.png' /></a></th></thead><tbody>
<tr><td><a href='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_muscle.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_muscle_m.png' /></a></td></tr>
<tr><td><a href='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_clustalw.png'><img src='http://wiki.pagan-msa.googlecode.com/git/images/454_reads_clustalw_m.png' /></a></td></tr>
<tr><td> Alignments with other popular MSA methods                                                                                                                           </td></tr></tbody></table>

<br>


<h3>Pileup alignment with strand search</h3>

If the correct strands of the reads are unknown, PAGAN can be run with option <code>--compare-reverse</code> that performs both forward and reverse-complement alignment and chooses the better one:<br>
<br>
<pre><code>pagan --pileup-alignment --use-consensus --454 --queryfile 454_reads_reversed.fas \<br>
--outfile 454_reads_reversed_pagan --compare-reverse<br>
</code></pre>

This currently only works with pileup alignment.<br>
<br>
<br>
<h3>Pileup alignment with query translation</h3>

If the strand of the reads is unknown and the reads come from protein-coding sequences (e.g. from RNA-seq experiment), PAGAN can be run with option <code>--find-best-orf</code> that searches for open reading frames in the query (both in forward and reverse-complement strands) and chooses the one giving the best alignment:<br>
<br>
<pre><code>pagan --pileup-alignment --ref-seqfile human.fas --queryfile input_ngs_primates.fas \<br>
--translate --find-best-orf<br>
</code></pre>

The reference sequence should be DNA (and translated with option <code>--translate</code>) or the resulting alignment cannot be back-translated to DNA. This option does not correct for reading frames and may thus not work well with data coming e.g. from 454.<br>
<br>
This currently only works with pileup alignment.<br>
<br>
<br>
<br>

<a href='PAGAN#Using_PAGAN.md'>back to top</a>

<hr />

<br>

<h1>Additional program options</h1>

Some of the options printed by <code>./pagan --help</code> relate to unfinished features and may not function properly. Only the main options are documented here.<br>
<br>
<br>

<h2>Generic options</h2>

<ul><li>Option <code>--silent</code> minimises the output (doesn't quite make it silent, though).</li></ul>

<ul><li>Options <code>--indel-rate</code> can be used adjust the insertion and deletion rates. Although it would be possible to consider the two processes separately, this has not been implemented yet.</li></ul>

<ul><li>Options <code>--gap-extension</code> and <code>--end-gap-extension</code> define the gap extension probability for regular and terminal gaps. For meaningful results, the latter should be greater (and, for pair-end data, equal to <code>--pair-read-gap-extension</code>).</li></ul>

<ul><li>Options <code>--dna-kappa</code> and <code>--dna-rho</code> affect the DNA substitution scoring matrix; base frequencies are estimated from the data.</li></ul>

<ul><li>Options <code>--codons</code> translates DNA sequences to codons and aligns them using the codon substitution model. (experimental)</li></ul>

<ul><li>Options <code>--scale-branches</code>, <code>--truncate-branches</code> and <code>--fixed-branches</code> override the branch lengths defined in the guide tree. By default, long branches are truncated to make the scoring matrix more informative; this can be prohibited with <code>--real-branches</code>.</li></ul>

<ul><li>Option <code>--output-ancestors</code> writes the parsimony-reconstructed ancestral sequences for the internal nodes of the tree. The tree indicating the nodes is written in <code>outfile.anctree</code>.</li></ul>

<ul><li>Option <code>--config-file file_name</code> specifies a config file. If an option is specified both in a config file and as a command-line argument, the latter one overrides the former.</li></ul>

<ul><li>Option <code>--config-log-file file_name</code> specifies a log file where (non-default) options used for the analysis are written.  The format is compatible with the option input and the file can be used a config file.</li></ul>

There are many parameters related to "insertion calling", the type and amount of phylogenetic information required to consider insertion-deletion as an insertion and thus prevent the later matching of those sites. These parameters are still experimental (although some of them are used and affect the resulting alignment) and will be described in detail later.<br>
<br>
<br>

<h2>Phylogenetic placement options</h2>

Some options are only relevant for the placement of sequences into existing alignment and many of those require FASTQ or NHX formatted input.<br>
<br>
<ul><li>Option <code>--qscore-minimum</code> sets the Q-score threshold for sites to be masked (replaced with N's for alignment, shown in lower case in the output); <code>--allow-skip-low-qscore</code> further allows skipping those sites (usefulness of this is uncertain). Masking is done by default (see <code>./pagan --help</code> for the default threshold) and can be disabled with option <code>--no-fastq</code> that prohibits all Q-score-based pre-processing done either by default or chosen by the user (e.g. trimming and 454-specific modelling).</li></ul>

<ul><li>Option <code>--trim-read-ends</code> enables the trimming of FASTQ reads;  <code>--trim-mean-qscore</code>, <code>--trim-window-width</code> and  <code>--minimum-trimmed-length</code> define the minimum Q-score and width for the sliding window and the minimum length for the trimmed read. Trimming progresses inwards from each end until the mean Q-score for the window exceeds the score threshold; if the read is shortened below the length threshold, it is discarded. The length of removed (trimmed) fragments is indicated in the sequence name field in the format <code>P1ST\$l1:P1ET\$l2</code> where <code>\$l1</code> and <code>\$l2</code> refer to the start and end of the read. If the sequences consists of a read pair, the trimming of the right-hand side read is similarly indicated using the tag <code>P2</code>.</li></ul>

<ul><li>Option <code>--rank-reads-for-nodes</code> ranks the sequences assigned to a node and aligns them in that order. The ranking is based on their score in the placement alignment used to decide between the alternative nodes. If sequences are assigned to one node each, one round of alignments against each node is performed to define the ranking before the final multiple alignment.</li></ul>

<ul><li>Reads fully embedded in other reads can be discarded: <code>--discard-overlapping-reads</code> identifies reads that overlap in the placement alignment and removes ones that are fully embedded in another one; <code>--discard-overlapping-identical-reads</code> extends this by checking that the embedded read is identical (on base level) to the longer read before discarding it; <code>--discard-pairwise-overlapping-reads</code> makes all the pairwise alignments to identify embedded reads.</li></ul>

<ul><li>Option <code>--query-distance</code> sets the expected distance between the query and the pseudo-parent node (against which the query is aligned) and thus affects the substitution scoring used in the alignment. Having the distance very short (default), the alignment is stringent and expects high similarity.</li></ul>

<ul><li>Queries with too few sites aligned against sites of reference sequences are discarded. (The stringency of the alignment is set using the option above.) Options <code>--min-query-overlap</code> and  <code>--min-query-identity</code> set the required overlap and base identity for accepting the query.</li></ul>

The rest of the options are either not important for basic use or self-explanatory (or both).<br>
<br>
<br>
<br>

<a href='PAGAN#Using_PAGAN.md'>back to top</a>

<hr />

<br>

<h1>Inference of ancestral sequences for existing alignments</h1>

The features required for phylogenetic placement of queries can be used without any queries, too. Command:<br>
<br>
<pre><code>./pagan --ref-seqfile alignment_file --ref-treefile tree_file --xml<br>
</code></pre>

writes the aligned sequences from <code>alignment_file</code> to files <code>outfile.fas</code> and <code>outfile.xml</code>, thus providing a tool to convert FASTA files to HSAML format. This maybe more interesting with option <code>--output-ancestors</code>. Command:<br>
<br>
<pre><code>./pagan --ref-seqfile alignment_file --ref-treefile tree_file --output-ancestors<br>
</code></pre>

includes the parsimony-reconstructed internal nodes in the FASTA output, providing a efficient tool to infer gap structure for ancestral sequences based on existing alignments. The tree indicating the ancestral nodes is written in <code>outfile.anctree</code>.<br>
<br>
<br>
<br>

<a href='PAGAN#Using_PAGAN.md'>back to top</a>

<hr />

<br>

<h1>Configuration files: input, output and format</h1>

Configuration files contain option names and values separated by <code>=</code> sign, one option per row. Rows starting with a hash sign <code>#</code> are comments and ignored. Thus, if the content of file <code>config.cfg</code> is:<br>
<pre><code># this is an uninformative comment<br>
ref-seqfile = reference_alignment.fas<br>
ref-treefile = reference_tree.nhx<br>
queryfile = illumina_reads.fastq<br>
outfile = read_alignment<br>
trim-read-ends = 1<br>
</code></pre>

the command:<br>
<br>
<pre><code>./pagan config.cfg<br>
</code></pre>

(or <code>./pagan --config-file config.cfg</code>)<br>
<br>
is equivalent to:<br>
<br>
<pre><code>./pagan --ref-seqfile reference_alignment.fas --ref-treefile reference_tree.nhx \<br>
  --queryfile illumina_reads.fastq --outfile read_alignment --trim-read-ends<br>
</code></pre>

By adding the option <code>--config-log-file config.cfg</code> in the command above, PAGAN creates a config file that is equivalent with the one above (with some more comments). Config files can, of course, be written or extended manually using the same format. One should note, however, that also boolean options need a value assigned, such as <code>trim-read-ends = 1</code> in the example above. If a boolean option is not wanted, it should not specified in the config file (or it should be commented out with a hash sign) as setting an option e.g. <code>0</code> or <code>false</code> does not disable it.<br>
<br>
Options in a config file are overridden by re-defining them on command line. Thus, the command:<br>
<br>
<pre><code>./pagan config.cfg --outfile another_name<br>
</code></pre>

is the same as the one above except that the results will be placed to a file with another name.<br>
<br>
<br>
<br>

<a href='PAGAN#Using_PAGAN.md'>back to top</a>