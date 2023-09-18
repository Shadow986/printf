#!/bin/bash

# Remove trailing white spaces
find . -name '*.c' -o -name '*.h' | xargs sed -i 's/[[:space:]]*$//'

# Adjust the code according to the provided errors and warnings
find . -name '*.c' | xargs awk '
{
    gsub("{[[:space:]]*$", " {")
    gsub("}$", "}")
    gsub("^ *#", "#")
    gsub("^ *//", "//")
    gsub("\t", "    ")
    print
}
' > temp_file && mv temp_file

# Fix the parameter and member descriptions
find . -name '*.c' | xargs awk '
/function [^(]*\([^)]*\)/ {
    if (!match($0, "No description found for parameter or member")) {
        sub(/{/,"")
        sub(/\([^)]*\)/,"")
        sub(/^[[:space:]]+/,"")
        sub(/[[:space:]]+$/,"")
        print $0
    }
    else {
        sub("attribute((unused))", "")
        print
    }
}
' > temp_file && mv temp_file
