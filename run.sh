#!/bin/bash
# @author   breadOnLaptop

# check argument
if [ -z "$1" ]; then
    echo "[ERROR] No file specified"
    echo "[INFO] Usage: $0 <filename.cpp>"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "[ERROR] File '$1' not found."
    exit 1
fi

# variables
TARGET_FILE="$1"
OUTPUT_FILE="./build/sol"

echo "[INFO] Compiling $TARGET_FILE..."
if g++ -std=c++23 "$TARGET_FILE" -o "$OUTPUT_FILE" -Wall -Wextra; then
    echo -e "Compilation successful! Running program...\n--------------------------------"
    "$OUTPUT_FILE"
    echo -e "--------------------------------\nProgram exited."

    exit 0
fi
