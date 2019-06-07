#!/bin/bash
pad_n=${#1}
seq $1 | awk -v n=$1 -v pad_n=$pad_n 'BEGIN {srand(); format = "%0"pad_n"d %d\n"}{ printf(format, int(rand() * n), $1)}' | sort -n | cut -c $(($pad_n + 2))-
