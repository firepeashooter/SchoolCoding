#!/bin/bash

if (($# == 0)); then
  exit 0
fi

#MAKE SURE WE LEARNED THIS OR CAN JUSTIFY IT I FOUND IT ON THE INTERNET
if [[ ! -e "$1" ]]; then
  echo "Hide.sh: cannot access $1"
  exit 1
fi


fileName=$(basename $1)
directory=$(dirname $1)

mv "$directory/$fileName" "$directory/.$fileName"
chmod g=--- "$directory/.$fileName"
chmod o=--- "$directory/.$fileName"

