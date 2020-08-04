#!/bin/bash
PIN_OUT=1
while [ $PIN_OUT = 1 ]
do
   PIN_OUT=`gpio input 80`
   sleep 0.01
done
echo "MIC_SEN"
