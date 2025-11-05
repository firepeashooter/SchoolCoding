#!/usr/bin/env bash
# shuffle.sh str
# Shuffles the characters of the string str printing the shuffled
# string to standard output.
# randperm n
# Outputs a random permutation of the integers 0, 1, ..., n-1


randperm() {
local n=$1
echo $(shuf -i 0-$n | tr '\n' ' ')
}
# remainder of your script goes here

#Exit if there are no commands given
if (( $# == 0)); then
    exit
fi

string=$1
rand=$(randperm $((${#string} - 1)))



#Create a new string we need to splice

#Loop through rand and build the new string

#for int in rand 
    #newstring += string[int]


for num in $rand; do
    newString+="${string:num:1}"
done

echo $newString