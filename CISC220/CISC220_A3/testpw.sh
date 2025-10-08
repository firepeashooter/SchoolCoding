#!/bin/bash

password=$1
status=0

if (($# == 0)); then
    echo "Usage: testpw.sh password"
    exit 1
fi


if [[ ${password} =~ [[:space:]] ]]; then
    echo "password cannot contain whitespace" >&2
    status=2
fi


if (( ${#password} < 8)); then
    echo "password length less than 8" >&2
    status=2
fi

if [[ ! ${password} =~ [[:alpha:]] ]]; then
    echo "password must contain at least one letter" >&2
    status=2
fi

if [[ ! ${password} =~ [[:digit:]] ]]; then
    echo "password must contain at least one number" >&2
    status=2
fi

if [[ ! ${password} =~ [[:punct:]] ]]; then
    echo "password must contain at least one symbol" >&2
    status=2
fi

exit ${status}
