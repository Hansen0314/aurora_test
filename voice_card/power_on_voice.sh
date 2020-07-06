#!/bin/bash
# if [ -n $1 ]
# then
    # echo "Usage:"
    # echo "bash power_on_voice.sh 1"
    # echo "bash power_on_voice.sh 2"
    # exit 1
# fi
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
