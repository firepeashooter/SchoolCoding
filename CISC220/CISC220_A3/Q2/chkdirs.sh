#!/bin/bash
#
# chkdirs.sh: List incorrectly named directories

# list directories with spaces
spaces=$(find . -maxdepth 1 -type d -regex '.* .*' -print | sort)
if [[ -n $spaces ]]; then
  echo "Filenames with spaces:"
  echo "$spaces"
fi

spaces=$(find . -maxdepth 1 -type d -regex '.* .*' -print | sort)
if [[ -n $spaces ]]; then
  echo "Filenames with unusual characters:"
  echo "$spaces"
fi

spaces=$(find . -maxdepth 1 -type d -regex '.* .*' -print | sort)
if [[ -n $spaces ]]; then
  echo "Directories that should be renamed"
  echo "$spaces"
fi

