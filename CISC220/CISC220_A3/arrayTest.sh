#!/bin/bash




next() {
    local startItem=${arr[$1]}
    echo $startItem
    echo ${arr[@]}

    #startVal = whatever we are at when this is called
    #curVal = whatever we are at right now
    #loop through the array until curVal != startVal
    #return THAT index
}

arr=("$@")

next 0