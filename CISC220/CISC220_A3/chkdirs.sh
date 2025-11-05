#!/bin/bash
#
# chkdirs.sh: List incorrectly named directories


# list directories with spaces
spaces=$(find . -maxdepth 1 -type d -regex '.* .*' -print | sort)
if [[ -n $spaces ]]; then
  echo "Filenames with spaces:"
  echo "$spaces"
  echo
fi

# list directories with unusual character in their name
# anything that is not a - _ lowercase uppercase digit or space
# Regex the above and then negate it
unusual=$(find . -maxdepth 1 -type d -regex './.*[^0-9A-Za-z _-].*' -print | sort)

if [[ -n $unusual ]]; then
  echo "Filenames with unusual characters:"
  echo "$unusual"
  echo
fi


# list directories that might be missing the _ between the first and last name of the student

missing=$(find . -maxdepth 1 -type d -regex './.*[a-z][^ _-]*[A-Z].*' -print | sort)

if [[ -n $missing ]]; then
  echo "Filenames that might have incorrectly separated names:"
  echo "$missing"
  echo
fi

# list directories with unusual character in their name
# anything that is not a - _ lowercase uppercase digit or space
# Regex the above and then negate it
rename=$(find . -maxdepth 1 -type d -regex '.* .*|.*[^0-9A-Za-z _-].*' -print | sort)

if [[ -n $rename ]]; then
  echo "Directories that should be renamed:"
  echo "$rename"
  echo
fi


