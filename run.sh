#!/bin/sh

# $> sh run.sh			-> 0..100
# $> sh run.sh 10		-> 0..10
# $> sh run.sh -4 32	-> -4..32

MIN="1";
MAX="100";
TMPFILE="/tmp/push_swap.res";

case $# in 	# $# -> argc
	1) MAX="$1"; ;;
	2) MIN="$1"; MAX="$2"; ;; 
esac

# -f verife l'existence du fichier
if [ ! -f "push_swap" ] || [ ! -f "checker" ]; then
	make psre;
fi

ARG="$(ruby -e "puts ($MIN..$MAX).to_a.shuffle.join(' ')")";
time ./push_swap "--clean" $ARG | tee "$TMPFILE" | ./checker $ARG
echo "With list:";
echo "$ARG";
if [ -f "$TMPFILE" ]; then
	echo "Moves: [$(cat "$TMPFILE" | wc -l | sed "s/^[ ]*//g")]";
	echo "Details:";
	cat "$TMPFILE" | awk '{CMD[$0]++;c++;}END{for(a in CMD)print CMD[a] " ±" CMD[a]/c*100 "% " a;}' | sort -nr | sed "s/,.*%/%/g"
	rm -f "$TMPFILE";
fi
