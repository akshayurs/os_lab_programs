largest=$1
for i in $@
do
    if [ $i \> $largest ]
    then
        largest=$i
    fi
done
echo "largest element is $largest"