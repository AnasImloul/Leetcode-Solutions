# Runtime: 38ms (Top 81.29%) | Memory: 3.7 MB (Top 33.84%)
cnt=0
while read line && [ $cnt -le 10 ]; do
  let 'cnt = cnt + 1'
  if [ $cnt -eq 10 ]; then
    echo $line
    exit 0
  fi
done < file.txt
