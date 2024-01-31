#!/bin/sh

filesdir="$1"
searchstr="$2"
if [ "$#" -ne 2 ]
  then
    echo "Two arguments have not been provided. Try again with 2 arguments"
    exit 1
fi
if [ ! -d "$filesdir" ]
  then
    echo "Directory does not exist"
    exit 1
fi
X=$(find "$filesdir" -type f | wc -l)
#wc for word count -> counts newlines, words and bytes
# -l for counting just newlines
Y=$(grep -r "$searchstr" "$filesdir" | grep -c "$searchstr") 

echo "The number of files are ${X} and the number of matching lines are ${Y} in 10"
