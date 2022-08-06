if [ $1 \> $2 ]
then
    if [ $1 \> $3 ]
    then
        echo "$1 is largest"
    else
        echo "$3 is largest"
    fi
else
    if [ $2 \> $3 ]
    then
        echo "$2 is largest"
    else
        echo "$3 is largest"
    fi
fi