#1,case语句练习
#2,zip
#3,file ...
#4,将命令的值输出`file ..`(倒引号）,$(file ..),eval file ..
#!/bin/sh
echo $1
ftype=eval file $1
#ftype=`file $1`
#ftype=$(file $1)
echo $ftype
case $1 in
*.zip) 
    unzip $1;;
*.rar)
    rar x $1;;
*.tar)
    tar xvf $1;;
*.tar.bz2|*.tar.bz)
    tar jxvf $1;;
*)echo "$1 cannot be uncompressed!"
esac

