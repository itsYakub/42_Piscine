#!/bin/bash

# Write a command line that searches for all file names that end with ".sh" (without
# quotation marks) in the current directory and all its sub-directories. It should
# display only the file names without the .sh.

# Example of output :
# ```
# $>./find_sh.sh | cat -e
# find_sh$
# file1$
# file2$
# file3$
# $>
# ```

# This is basically a one-liner. We firstly get all the ".sh" files and then eec the basename command to get only the names of the found files, without their extensions.

find . -type f -iname "*.sh" -exec basename {} .sh \;
