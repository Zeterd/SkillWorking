#!/bin/bash

gpu_name=$(nvidia-smi | tail -n12 | head -n1 | awk '{print $3 $4 $5}')
gpu_temp=$(nvidia-smi | tail -n11 | head -n1 | awk '{print $3}')
mem_usg=$(nvidia-smi | tail -n11 | head -n1 | awk '{print $9}')
mem_total=$(nvidia-smi | tail -n11 | head -n1 | awk '{print $11}')
gpu_usage=$(nvidia-smi | tail -n11 | head -n1 | awk '{print $13}')

echo ""
echo "########### Information of GPU ###########"
echo ""
echo -e "Brand of GPU:\t\tNVIDIA"
echo -e "Model:\t\t\t$gpu_name"
echo -e "Temperature of GPU is:\t$gpu_temp"
echo -e "Memory (usage/total):\t$mem_usg / $mem_total"
echo -e "GPU usage:\t\t$gpu_usage"
echo ""
