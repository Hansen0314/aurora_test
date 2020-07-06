#!/bin/bash
if [ "$#" -lt "1" ]; then
   echo "usage: bash $0 100"
   echo "usage: bash $0 200"
   exit
fi
echo "EXT_12VON"
gpio set 71 
sleep 1
gpio clear 71
echo "EXT_R_RESET"
sleep 1
gpio set 47
sleep 1
gpio clear 47
if [ "$1" -ne 200 ]
then
   exit 1
fi 
echo "EXT_C_RESET"
sleep 1
gpio set 27
sleep 1
gpio clear 27
