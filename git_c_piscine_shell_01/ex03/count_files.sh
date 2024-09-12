#!/bin/bash

# Write a command line that counts and displays the number of regular files and
# directories in the current directory and all its sub-directories. It should include ".",
# the starting directory.

# Example of output:
# ```console
# $>./count_files.sh | cat -e
# 42$
# $>
# ```

find . -type f | wc -l
