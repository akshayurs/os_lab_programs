declare -A X
declare -A Y
declare -A Z

echo "Enter Size :"
read n
echo "Enter matrix X :"
for((i=0;i<$n;i++))
do
    for((j=0;j<$n;j++))
    do
        read X[$i,$j]
    done
done
echo "Enter matrix Y :"
for((i=0;i<$n;i++))
do
    for((j=0;j<$n;j++))
    do
        read Y[$i,$j]
    done
done
echo "matrix X :"
for((i=0;i<$n;i++))
do
    for((j=0;j<$n;j++))
    do
        echo -ne "${X[$i,$j]} "
    done
    echo 
done
echo ""
echo "matrix Y :"
for((i=0;i<$n;i++))
do
    for((j=0;j<$n;j++))
    do
        echo -ne "${X[$i,$j]} "
    done
    echo
done
echo
echo "Sum :"
for((i=0;i<$n;i++))
do
    for((j=0;j<$n;j++))
    do
        Z[$i,$j]=$(( ${X[$i,$j]}+${Y[$i,$j]} ))
		echo  -ne "${Z[$i,$j]} "
    done
    echo
done