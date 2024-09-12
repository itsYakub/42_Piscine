#!/bin/sh

# This line is responsible for printing the commit list
# It takes a few options:
# - "-n 5": git log will output only the 5 most recent commits from the list;
# - "-format=%H": logged message will be formated based on the string-format; "%H" is a placeholder for the full commit hash;
git log -n 5 --format=%H
