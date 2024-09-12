#!/bin/bash

#Write a command line that displays one line out of two for the command ls -l,
#starting from the first line.

# Example of output :
# ```console
# $>ls -l | cat -e
# total 4$
# -rw-rw-r-- 1 eagle eagle ** ** 15 15:46 skip.sh$
# -rw-rw-r-- 1 eagle eagle ** ** 15 15:41 tata$
# -rw-rw-r-- 1 eagle eagle ** ** 15 15:41 titi$
# -rw-rw-r-- 1 eagle eagle ** ** 15 15:41 toto$
# -rw-rw-r-- 1 eagle eagle ** ** 15 15:41 tutu$
# $>
# ```
# ```console
# $>./skip.sh | cat -e
# total 4$
# -rw-rw-r-- 1 eagle eagle ** ** 15 15:41 tata$
# -rw-rw-r-- 1 eagle eagle ** ** 15 15:41 toto$
# $>
# ```

ls -l | sed -n 'p;n'
