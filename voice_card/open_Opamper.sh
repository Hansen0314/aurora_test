#!/bin/bash
gpio clear 9  
gpio clear 76 
# 1 1
if [ $1 = 1 ]
then
     gpio set 70
     gpio clear 81
fi
if [ $1 = 2 ]
then
    gpio set 81
    gpio clear 70
fi
gpio clear 8 #power on
gpio set 78  #off mute
