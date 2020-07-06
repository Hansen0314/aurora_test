#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "This script must be run as root (use sudo)" 1>&2
	exit 1
fi

# install gpio

cd /bin/
wget https://raw.githubusercontent.com/turmary/EMSTS/master/scripts/bbb/gpio
chmod 775 /bin/gpio
GPIO_CHECK=`gpio`
if [ $GPIO_CHECK ]
then
    echo "cannot find gpio please check whether installed gpio successfully"
    exit 1
fi

# install phytool
cd /home/debian;git clone https://github.com/wkz/phytool
cd /home/debian/phytool
make
make install
PHYTOOL_CHECK=`phytool | tail -n 1`
if [ $PHYTOOL_CHECK ]
then
    echo "cannot find phytool please check whether installed phytool successfully"
    exit 1
fi

# install power-service
cd aurora_test/power-service
bash install.sh

# install voice-card

sh -c "echo uboot_overlay_addr0=/lib/firmware/BB-BONE-AUDI-02-00A0.dtbo >> /boot/uEnv.txt"
cd aurora_test/voice_card
alsactl restore 0 -f asound.state
cp asound.conf  /etc/asound.conf
echo "reboot to enable voice config"
sleep 10
reboot

