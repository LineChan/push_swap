#!/bin/sh

# $> sh run.sh			-> 0..100
# $> sh run.sh 10		-> 0..10
# $> sh run.sh -4 32	-> -4..32

MIN="1";
MAX="100";
case $# in 	# $# -> argc
	1) MAX="$1"; ;;
	2) MIN="$1"; MAX="$2"; ;; 
esac

# -f verife l'existence du fichier
if [ ! -f "push_swap" ] || [ ! -f "checker" ]; then
	make psre;
fi

ARG="$(ruby -e "puts ($MIN..$MAX).to_a.shuffle.join(' ')")";
time ./push_swap "--clean" $ARG | ./checker $ARG
echo "With list:";
echo "$ARG";
