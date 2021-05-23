OS="linux"
NUM=100

ARG=`ruby -e "puts (1..$NUM).to_a.shuffle.join(' ')"`;

#ARG='7 3 10 6 4 1 9 8 2 5';

echo $ARG

#gdb --args push_swap $ARG

./push_swap $ARG

echo -n "number of moves: " && \
./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_$OS $ARG
