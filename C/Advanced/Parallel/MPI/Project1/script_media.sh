#!/bin/zsh

array = ()

repeat 100 {val = $(mpirun -np 4 trab < matrix_inputs/input6);sleep 1;array+=($val)}

cont = 0
for v in "$(array[@])"
do
    cont = v + $cont
done

echo $($cont/100)
