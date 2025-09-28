#!/bin/bash

firstCommand=$1
secondCommand=$2
errorCode=$3

if (($firstCommand != $secondCommand)); then
  echo "ERROR: Expected $firstCommand command line argument, but received $secondCommand"
  exit $errorCode
fi
