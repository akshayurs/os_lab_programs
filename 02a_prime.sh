echo "Enter start and end :"
read start end
flag=1
for((i=start;i<=end;i++))
do
    flag=1
    for((j=2;j<i;j++))
    do
        if [ $(($i%$j)) == 0 ]
        then
            flag=0      
            break
        fi
    done
    if [ $flag == 1 ]
    then
        echo "$i "
    fi
done