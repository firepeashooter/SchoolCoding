#!/bin/bash

digit1=$(./rdigit.sh)
digit2=$(./rdigit.sh)
digit3=$(./rdigit.sh)

echo $(($(($digit1 * 10 ** 0)) + $(($digit2 * 10 ** 1)) + $(($digit3 * 10 ** 2))))
