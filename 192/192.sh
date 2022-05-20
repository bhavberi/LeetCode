# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | grep -wo '[[:alnum:]]\+' | sort | uniq -c | sort -bnr | awk '{print $2 " " $1}'
