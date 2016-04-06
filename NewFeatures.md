# Recent changes #

### v.0.46 ###
First integration of MAFFT and RAxML: PAGAN is now capable of computing a guide tree by first calling MAFFT and then RAxML.


### v.0.45 ###
Minor: code reorganised and recently created bugs fixed.


### v.0.44 ###
PAGAN can now anchor alignments with Exonerate or substring matching. As a result, significant speed ups in the alignment of long and/or very similar similar sequences.


### v.0.43 ###
Now properly functional multi-threading for standard multiple alignment:
by default, PAGAN uses all the cores available. This can be changed with `--threads #`.

### v.0.42 ###
First attempt to introduce multi-threading for standard multiple alignment.

### prior v.0.42 ###
See VERSION\_HISTORY in the source code