#!/bin/bash

# anything errors lead to break prog
set -e

# build main
make ascii85

# start with give all arguments
./ascii85 "$@"