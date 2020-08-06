#!/bin/bash
if [ "$#" -lt "1" ]; then
	   echo "usage: bash $0 1"
	      echo "usage: bash $0 2"
	         exit
fi
gpio clear 61
gpio clear 89
# 1 1
if [ $1 = 1 ]
then
     gpio set 88 
     gpio clear 69 
fi
if [ $1 = 2 ]
then
    gpio set 69 
    gpio clear 88 
fi
gpio clear 60 #power on
gpio set 68  #off mute
