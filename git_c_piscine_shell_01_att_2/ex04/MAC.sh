#!/bin/bash

# Write a command line that displays your machine’s MAC addresses. Each address
# must be followed by a line break.

# This one gives me a lot of struggles.
# Firstly, we retrieve the information about the ethernet connection via grep (searching for the "ether keyword").
# Then, via awk I'm searching for the second field of each field of the found lines and print it to the stdout (for extracting the second field we use $2 format, if I'd 4example use $1 the output would be "ether")
ifconfig | grep 'ether ' | awk '{print $2}'

