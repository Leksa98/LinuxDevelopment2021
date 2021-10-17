#!/bin/bash
tput clear
D=${1:-0.5}
y=0
x=0
IFS=
while read -r L
do
	x=0
	L=`echo $L | tr ' ' '\01' | od -tx1 -An --w=1000`
	IFS=" "
	for c in $L
	do
		if [ "$c" != "01" ]
		then 	
			echo $x $y $c
		fi
		x=$(($x+1)) 
	done
	IFS=
	y=$(($y+1))
done | shuf |
while IFS=" " read -r x y c
do
	tput cup $y $x
	echo -ne \\x$c
	sleep $D
done
tput cup $(tput lines) 0
