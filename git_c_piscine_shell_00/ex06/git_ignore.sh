#!/bin/bash

# This line will check all the files and directories that git MUST ignore
# - "--": the options given to "check-ignore". Double-minus indicates, that there wasn´t any option given;
# - "**/*": this option is specifying where the command should look for the ignored files. A "*" wildcard searches for all the files in the directories, and "**/*" wildcard searches through all the directories of the repo.
git check-ignore -- * **/*
