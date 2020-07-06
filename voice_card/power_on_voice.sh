#!/bin/bash
if [ "$#" -lt "1" ]; then
   echo "usage: bash $0 1"
   echo "usage: bash $0 2"
   exit
fi
/bin/bash open_Opamper.sh $1
while true
do
    CARD_STARUS=`aplay -l | grep card | awk '{print $1}'`
    if [ -n $CARD_STARUS ]
    then
        break
    fi
    sleep 1
done
sleep 2
arecord|aplay
if false; then 
if [ $1 = 1 ]
then
    PIN_OUT=`gpio input 79`
    while [ $PIN_OUT = 0 ]
    do
        PIN_OUT=`gpio input 79`
        sleep 0.01
    done
    echo "SPK_SEN1"
fi
if [ $1 = 2 ]
then
    PIN_OUT=`gpio input 77`
    while [ $PIN_OUT = 0 ]
    do
        PIN_OUT=`gpio input 77`
        sleep 0.01
    done
    echo "SPK_SEN2"
fi
PIN_OUT=`gpio input 80`
while [ $PIN_OUT = 0 ]
do
    PIN_OUT=`gpio input 80`
    sleep 0.01
done
echo "MIC_SEN"
fi
