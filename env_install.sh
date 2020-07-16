#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "This script must be run as root (use sudo)" 1>&2
	exit 1
fi

# install gpio
cp /home/debian/aurora_test/gpio /bin/
chmod +x /bin/gpio

# install phytool
cd /home/debian;git clone https://github.com/wkz/phytool
cd /home/debian/phytool
make
make install
cp /usr/local/bin/phytool /home/debian/aurora_test/eth0/

# install power-service
cd /home/debian/aurora_test/power-service
bash install.sh

# install voice-card
sh -c "echo uboot_overlay_addr0=/lib/firmware/BB-BONE-AUDI-02-00A0.dtbo >> /boot/uEnv.txt"
cd /home/debian/aurora_test/voice_card
cp asound.state /var/lib/alsa/
cp asound.conf  /etc/
echo "reboot to enable voice config"
sleep 10
reboot

