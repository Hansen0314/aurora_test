#!/bin/bash
if [ "$#" -lt "1" ]; then
   echo "usage: bash $0 1"
   echo "usage: bash $0 2"
   exit
fi
/bin/bash open_Opamper.sh $1
while true
do
    CARD_STARUS=`aplay -l | grep card | awk '{print $3}'`
    if [ $CARD_STARUS = 'B' ]
    then
        sleep 2
        break
    fi
    sleep 1
done
arecord -f dat -D hw:0 | aplay -f dat -D hw:0