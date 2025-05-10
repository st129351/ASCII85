#!/bin/bash

# anything errors lead to break prog
set -e

# build tests
make tests

# start with give all arguments
./tests "$@"