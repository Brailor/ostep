#! /bin/bash

# echo -1 >&2
# exit 1
echo "this will count the words in file: $1"
wc "$1"
