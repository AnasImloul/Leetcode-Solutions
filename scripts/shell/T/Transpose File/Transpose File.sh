# Runtime: 354ms (Top 46.21%) | Memory: 3.4 MB (Top 97.24%)
ncol=`head -n1 file.txt | wc -w`

for i in `seq 1 $ncol`
do
    echo `cut -d' ' -f$i file.txt`
done
