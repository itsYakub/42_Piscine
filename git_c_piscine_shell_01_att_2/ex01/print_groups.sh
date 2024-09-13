#!/bin/bash

# Write a command line that will display the list of groups for which the login,
# contained in the environment variable FT_USER , is a member. Separated by
# commas without spaces.

# Examples :
# - for FT_USER=nours, the result is "god,root,admin,master,nours,bocal" (with-
# out quotation marks)
# ```console
# $>./print_groups.sh
# god,root,admin,master,nours,bocal$>
# ```
# - for FT_USER=daemon, the result is "daemon,bin" (without quotation marks)
# ```console
# $>./print_groups.sh
# daemon,bin$>
# ```

# Firstly, we retreive the information about the user for $FT_USER environmental variable. To get the name-only version for all the groups we use the flag -nG.
# Then we pipe that information to tr to replace ' ' with ',' and remove the newline character from the end

id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'
