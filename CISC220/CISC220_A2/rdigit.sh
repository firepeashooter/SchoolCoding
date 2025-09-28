#!/bin/bash
numbers="0123456789"

fold -w 1 <<<$numbers | shuf | head -1
