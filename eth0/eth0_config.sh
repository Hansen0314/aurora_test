#!/bin/bash
TEST_URL=192.168.4.2
if [[ $EUID -ne 0 ]]; then
	echo "This script must be run as root (use sudo)" 1>&2
	exit 1
fi
LINK_STATUS=`dmesg | grep eth0 | tail -n 1 | awk '{print $8}'`
echo $LINK_STATUS
if [ $LINK_STATUS = "ready" ]
then
	ping $TEST_URL
	exit 1
fi
#LAN8710A disable Auto-Negotiation
phytool write eth0/0/0x0 0x000 
phytool read eth0/0/0x0      
# LAN8710A disable AUTO-MDIX
phytool write eth0/0/0x1b 0xa00b 
phytool read eth0/0/0x1b      

sleep 10

ping $TEST_URL
