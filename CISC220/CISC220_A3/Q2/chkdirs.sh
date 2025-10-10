#!/bin/bash
#
# chkdirs.sh: List incorrectly named directories

# list directories with spaces
spaces=$(find . -maxdepth 1 -type d -regex '.* .*' -print | sort)
if [[ -n $spaces ]]; then
  echo "Filenames with spaces:"
  echo "$spaces"
fi

# list directories with unusual character in their name
# anything that is not a - _ lowercase uppercase digit or space
# Regex the above and then negate it
unusual=$(find . -maxdepth 1 -type d -regex '..[^-_[:lower:][:upper:][:digit:][:space:]].*' -print | sort)
echo $unusual
if [[ -n $unusual ]]; then
  echo "Filenames with unusual characters:"
  echo "$unusual"
fi

# list directories that might be missing the _ between first and last name of a student
# maybe check for " " followed by capital those are maybe missing them
spaces=$(find . -maxdepth 1 -type d ! -regex '.* .*' -print | sort)
if [[ -n $spaces ]]; then
  echo "Filenames with spaces:"
  echo "$spaces"
fi
