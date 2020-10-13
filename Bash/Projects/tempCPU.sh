#!/bin/bash

sensors > temp.txt

var=$(cat /proc/cpuinfo | grep "model name" | head -n1 | awk '{print $4}')
cpu_brand=${var::-3}

cpu_model=$(cat /proc/cpuinfo | grep "model name" | head -n1 | awk '{print $6}')

cpu_num_cores=$(expr $(cat /proc/cpuinfo | grep "processor" | wc -l) - 4)

cpu_num_threads=$(cat /proc/cpuinfo | grep "processor" | wc -l)

cpu_speed=$(cat /proc/cpuinfo | grep "model name" | head -n1 | awk '{print $9}')

cpu_temp=$(tail -n 19 temp.txt | head -n 1 | awk '{print $4}' | fold -w1 | head -n 3 | tail -n 2 | paste -sd "")

cpu_fan=$(tail -n 3 temp.txt | head -n 1 | awk '{print $2}')

echo ""
echo "########### Information of CPU ###########"
echo ""
echo -e "Brand of GPU:\t\t\t$cpu_brand"
echo -e "Model of CPU:\t\t\t$cpu_model"
echo -e "Number of cores/threads:\t$cpu_num_cores/$cpu_num_threads"
echo -e "Speed of CPU(GHz):\t\t$cpu_speed"
echo -e "Temperature of CPU is:\t\t$cpu_tempºC"
echo ""
