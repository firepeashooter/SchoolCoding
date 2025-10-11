#!/bin/bash

if (( $# < 3)); then
	echo "rename.sh: too few arguments" >&2
	exit 1
fi

#For number of arguments - 2 (the first two) rename that many files
from=$1
to=$2



#How do we check if no files were renamed?

shift 2
renamed=0

for arg in "$@"; do
	#Check if the file name changed
	newName=${arg/$from/$to}
	if [[ "$arg" != "$newName" ]]; then
		mv ./$arg ./$newName
		((renamed++))
	fi

done

if (($renamed == 0)); then
	echo "rename.sh: no files contain the string $from" >&2
	exit 2
fi