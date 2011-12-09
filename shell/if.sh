#! /bin/sh

if [ -f /bin/bash ]
then echo "a file"
else echo "not a file"
fi
if :;then echo "always true"; fi

echo "is it morning? yes or no."
read YES_OR_NO
if [ "$YES_OR_NO" = "yes" ];then
    echo "Good morning!"
elif [ "$YES_OR_NO" = "no" ];then
    echo "Good afternoon!"
else
    echo "Sorry,$YES_OR_NO not regnized.Enter yes or no."
	exit 1
fi
exit 0
