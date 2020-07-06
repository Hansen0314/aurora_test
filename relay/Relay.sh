#!/bin/bash
echo "EXT_12VON"
gpio set 71 
sleep 1
gpio clear 71
echo "EXT_R_RESET"
sleep 1
gpio set 47
sleep 1
gpio clear 47
echo "EXT_C_RESET"
sleep 1
gpio set 27
sleep 1
gpio clear 27
