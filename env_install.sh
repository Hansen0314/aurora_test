#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "This script must be run as root (use sudo)" 1>&2
	exit 1
fi

# install gpio
<<<<<<< HEAD
cd /home/debian;git clone https://github.com/turmary/EMSTS.git
cp /home/debian/EMSTS/scripts/bbb/gpio /bin/
chmod +x /bin/gpio
=======
cd /bin/
wget https://raw.githubusercontent.com/turmary/EMSTS/master/scripts/bbb/gpio
chmod 775 /bin/gpio
>>>>>>> 85349c7732b7f947a60bf50bc3e80343eb74b20a

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
alsactl restore 0 -f asound.state
cp asound.conf  /etc/asound.conf
echo "reboot to enable voice config"
sleep 10
reboot

