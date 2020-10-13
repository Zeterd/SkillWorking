#!/bin/bash

sensors > temp.txt
var=$(tail -n 19 temp.txt | head -n 1 | awk '{print $4}')

temp=$(echo "$var" | fold -w1 | head -n 3 | tail -n 2 | paste -sd "")
cpu_fan=$(tail -n 3 temp.txt | head -n 1 | awk '{print $2}')

echo "########### Information of CPU ###########"
echo ""
echo -e "Brand of CPU:\t\tNVIDIA"
echo -e "Model:\t\t\t$gpu_name"
echo -e "Temperature of GPU is:\t$gpu_temp"
echo -e "Memory (usage/total):\t$mem_usg / $mem_total"
echo -e "GPU usage:\t\t$gpu_usage"
