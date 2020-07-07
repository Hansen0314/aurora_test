#!/bin/bash
if [ "$#" -lt "1" ]; then
   echo "usage: bash $0 100"
   echo "usage: bash $0 200"
   exit
fi

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

PIN_OUT=`gpio input 75`
while [ $PIN_OUT = 0 ]
do
    PIN_OUT=`gpio input 75`
    sleep 0.01
done

echo "EXT_SEN"
if [ "$1" -ne 200 ]
then
   exit 1
fi 

PIN_OUT=`gpio input 65`
while [ $PIN_OUT = 1 ]
do
    PIN_OUT=`gpio input 65`
    sleep 0.01
done
echo "SEN2_IN"