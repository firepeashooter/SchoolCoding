#!/bin/bash

if (( $# < 3)); then
	echo "rename.sh: too few arguments" >&2
	exit 1
fi

#For number of arguments - 2 (the first two) rename that many files
from=$1
to=$2
file=$3

newName=${file/$from/$to}

mv ./$file ./$newName


#How do we check if no files were renamed?

for args in $#; do
	echo $args
done
