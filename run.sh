#!/bin/bash


# Check if input file is provided
if [ $# -eq 0 ]; then
    echo "Usage: ./run.sh <path-to-test-file>"
    exit 1
fi

# Run the parser on the provided file
./parser "$1" -o dls
