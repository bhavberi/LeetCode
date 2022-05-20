a=`cat file.txt | wc -l`
b=9
if [[ $a -gt 9 ]]
then
{
cat file.txt | head -n 10 | tail -n 1
}
fi
