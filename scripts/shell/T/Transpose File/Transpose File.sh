ncol=`head -n1 file.txt | wc -w`

for i in `seq 1 $ncol`
do
    echo `cut -d' ' -f$i file.txt`
done