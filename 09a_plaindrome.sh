echo "Enter a number "
read num
temp=$num
rev=0
while(( $num != 0 ))
do
    rem=$(($num%10))
    num=$(($num/10))
    rev=$(($rev*10 + $rem))
done
if [ $rev == $temp ]
then
    echo "$temp is a plaindrome"
else
    echo "$temp is not a plaindrome"
fi