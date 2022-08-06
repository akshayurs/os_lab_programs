echo "Choose Operation"
echo "1) Addition"
echo "2) subtraction"
echo "3) Multiplication"
echo "4) Division"
echo "5) Remainder"
read choice
echo "Enter two number"
read a b
case $choice in
1) echo $(($a+$b)) ;;
2) echo $(($a-$b)) ;;
3) echo $(($a*$b)) ;;
4) echo $(($a/$b)) ;;
5) echo $(($a%$b)) ;;
esac