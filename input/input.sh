#!/bin/bash
PIN_OUT=`gpio input 44`
while [ $PIN_OUT = 1 ]
do
    PIN_OUT=`gpio input 44`
    sleep 0.01
done
echo "CALL_IN"

PIN_OUT=`gpio input 46`
while [ $PIN_OUT = 1 ]
do
    PIN_OUT=`gpio input 46`
    sleep 0.01
done
echo "SEN1_IN"

PIN_OUT=`gpio input 65`
while [ $PIN_OUT = 1 ]
do
    PIN_OUT=`gpio input 65`
    sleep 0.01
done
echo "SEN2_IN"

PIN_OUT=`gpio input 75`
while [ $PIN_OUT = 0 ]
do
    PIN_OUT=`gpio input 75`
    sleep 0.01
done
echo "EXT_SEN"
