# Runtime: 135 ms (Top 65.61%) | Memory: 3.8 MB (Top 31.12%)
cat words.txt | tr -s ' ' '\n' | sort | uniq --count | sort -r | awk '{print $2 " " $1}'
