#!/bin/bash
COUNTER=0
SOMOOTH_FACTOR=3
while true
do
    WDOG_VAULE=`/opt/EMSTS/scripts/bbb/gpio input 49` ##get mpu single
    if [ $WDOG_VAULE = 1 ] ##if WDOG_VAULE is high
    then
        COUNTER=`expr $COUNTER + 1`
    else
        COUNTER=0
    fi
    if [ $COUNTER -ge $SOMOOTH_FACTOR ] ##if counter > 5
    then
        /opt/EMSTS/scripts/bbb/gpio set 48  ##feedback to mpu
        sleep 0.2
        /opt/EMSTS/scripts/bbb/gpio clear 48  ##feedback to mpu
        echo "get feedback from mpu"
        COUNTER=0
    fi
    sleep 0.1
done

