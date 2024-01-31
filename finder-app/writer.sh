#!/bin/sh

writefile="$1"
writestr="$2"

if [ "$#" -ne 2 ]
  then
    echo "2 Arguments have not been provided. Try again with 2 arguments"
    exit 1
fi

mkdir -p $( dirname "$writefile") && touch "$writefile"
    echo "$writestr" > "$writefile"
    echo "content created in file"

if [ -f "$writefile" ] 
  then
    echo 'File exists'
else
  echo 'File does not exist.'

fi
