#!/bin/bash

# Compresses the elements of the array arr storing the
# result in the array enc
comp() {

    

    n=${#arr[@]}

    if (( n > 0)); then
        start=0
        val=${arr[$start]}
        finished=1

        while ((finished == 1)); do
            end=$(next "$start")

            if ((end == -1)); then
                end=$n
                finished=0
            fi

            count=$(( end - start ))
            enc+=("$count")
            enc+=("$val")

            start=$end
            val=${arr[$start]}
        done
    fi

}


# Finds the index of the next element in arr that is
# different (not equal to) from the element located at the
# specified starting index; e.g.,
#
# next 3
#
# finds the index of the next element in arr that is not
# equal to the element at the starting index 3.
#
# The value of the found index is always greater than the
# specified index, or is -1 if all of the remaining
# elements in arr starting from the specified index are equal.
#
# The found index is printed to standard output.
next() {
    local startItem=${arr[$1]}
    local curIndex=$1
    local curVal=$startItem


    until [[ "$curVal" != "$startItem" ]]; do
        ((curIndex++))

        if (($curIndex >= ${#arr[@]})); then #prints -1 if the 
            echo "-1"
            exit
        fi

        curVal=${arr[$curIndex]}
    done

    echo $curIndex #VERY IMPORTANT. THIS IS THE INDEX OF THE NEXT DIFFERENT VARIABLE IN THE ARRAY


}

#Create the encoded array
declare -a enc
# create array arr from command line arguments
arr=("$@")
# compress the array
comp
# print elements of enc on one line with one space between elements
echo "${enc[@]}"