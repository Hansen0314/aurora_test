# Aurora Software Guide

**Seeed Technology**

This software provide some shell commands to demo how to drive devices on the Aurora Device.

## Specification

For Aurora 100
|Item|Values|
|----|------|
|Memory|512MB DDR3 RAM|
|Storage| 4GB 8-bit eMMC on-board flash<br>SD slot|	
|Peripheral Interface| 1 x USB Host<br>1 x 100M Ethernet interface<br>1 x Record interface<br>1 x Play interface<br>2 x Relay output interface(MAX 30V/2A))<br>2 x GPIO input interface<br>1 x Extern 12V interface(MAX 2A)<br>1 x USB OTG<br>1 x SD card interface <br>2 x TTL UART|
|On-board LED|1 x Power LED<br>1 x user-defined LED<br>4 x user-defined LED|
|Power|1 x DC interface (24V/2.5A)|
|Button|1 x reset button<br>1 x power button<br>1 x boot button<br>1 x user-defined button|
|Knob|1 x sound volume knob|
|Operating temperature(C) | 0 ~ 90 (refer to [am3358](https://www.ti.com/product/AM3358))|

For Aurora 200

|Item|Values|
|----|------|
|Memory|512MB DDR3 RAM|
|Storage| 4GB 8-bit eMMC on-board flashsud<br>SD slot|	
|Peripheral Interface| 1 x USB Host<br>4 x 100M Ethernet interface<br>1 x Record interface<br>2 x Play interface<br>3 x Relay output interface(MAX 30V/2A)<br>3 x GPIO input interface<br>1 x Extern 12V interface(MAX 2A)<br>1 x USB OTG<br>1 x SD card interface <br>2 x TTL UART|
|On-board LED|1 x Power LED<br>1 x User-defined LED<br>1 x Network status LED<br>4 x user-defined LED|
|Power|1 x DC interface(24V/2.5A)|
|Button|1 x reset button<br>1 x power button<br>1 x boot button<br>1 x user-defined button|
|Knob|1 x Sound volume knob|
|Operating temperature(C) | 0 ~ 90 (refer to [am3358](https://www.ti.com/product/AM3358))|

## Hardware Overview

It is convenient to use this hardware overview for finding the location of the hardware.
<div STYLE="page-break-after: always;"></div>
For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/aurora100-1.png)

- **1. LED:** Include power LED and user-defined LED.

- **2. USB OTG:** This USB Port is used to connect to your computer via serial mode of putty.

- **3. USB Host:** You can plug USB device, such as USB mouse,USB keyboard and USB flash disk into Aurora via those two USB hosts.

- **4. Ethernet interface:** Access to the Internet.

- **5. Extern Interface:** Include 1 x Record interface , 1 x Play interface , 2 x Relay output interface , 2 x GPIO input interface , 1 x Extern 12V interface.

- **6. Knob:** Adjust the speaker volume.

- **7. Power switch:** Power on or power off the Aurora.

- **8. DC jack:** Input 24V/2.5A power.

- **9. TTL UART:** You also can connect the Aurora with your computer via this UART port.

- **10. SWIM interface:** You can use this jack to update the mpu(stm8) firmware.

- **11. SD Card Slot:** To plug in micro-SD card to update the Aurora firmware.

- **12. STM8:** Software power switch chip for Aurora.

- **13. MTFC4GACAJCN:** 4GB EMMC Storage.

- **14. MT41K256M16TW:** 512M DDR3 RAM.

- **15. AM3358:** Main controller.

- **16. TPS65217CRSLR:** Power Management Chip.

- **17. TLV320AIC3104:** Audio codec chip.

- **18. TPA3106D1:** Amplifier for speaker.

- **19. LAN8710A:** 100M Network cable drive network card.

- **20. Power button:** power on or power off the AM3358.

- **21. MAX9814ETD:** Amplifier for Mic.

- **22. Reset button:** Reset the AM3358.

- **23. Boot button:** if pressed boot to sd card.

- **24. USER LED:** four user-defined LED.

- **25. BUTTON:** user-defined BUTTON.

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/aurora200-1.png)

- **1. Knob:** Adjust the speaker volume.

- **2. SD Card Slot:** To plug in micro-SD card to update the Aurora firmware.

- **3. USB OTG:** This USB Port is used to connect to your computer via serial mode of putty.

- **4. USB Host:** You can plug USB device, such as USB mouse,USB keyboard and USB flash disk into Aurora via those two USB hosts.

- **5. Ethernet interface:** 4 x Ethernet Interface be controlled by the switch chip.

- **6. TTL UART:** You also can connect the Aurora with your computer via this UART port.

- **7. DC jack:** Input 24V/2.5A power.

- **8. Power switch:** Power on or power off the Aurora.

- **9. Extern Interface:** Include 1 x Record interface , 2 x Play interface , 3 x Relay output interface , 3 x GPIO input interface , 1 x Extern 12V interface.

- **10. LED:** Include power LED and user-defined LED , network status LED.

- **11. SWIM interface:** You can use this jack to update the mpu(stm8) firmware.

- **12. STM8:** Software power switch chip for Aurora.

- **13. TPA3106D1:** Amplifier for speaker.

- **14. MAX9814ETD:** Amplifier for Mic.

- **15. MT41K256M16TW:** 512M DDR3 RAM.

- **16. AM3358:** Main controller.

- **17. MTFC4GACAJCN:** 4GB EMMC Storage.

- **18. TPS65217CRSLR:** Power Management Chip.

- **19. TLV320AIC3104:** Audio codec chip.

- **20. LAN8710A:** 100M Network cable drive network card.

- **21. RTL8305NB:** Ethernet switch controller.

- **22. Boot button:** if pressed boot to sd card.

- **23. Power button:** power on or power off the AM3358.

- **24. Reset button:** Reset the AM3358.

- **25. USER LED:** four user-defined LED.

- **26. BUTTON:** user-defined BUTTON.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//Hardware_back.png)

## Extern Interface pinout

It is very useful when we test there pin.

For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//100_Extern_Interface_pinout.png)
![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//100_Extern_Interface_pinout-1.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//200_Extern_Interface_pinout.png)
![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//200_Extern_Interface_pinout-1.png)

## Introduction To Software

### Preparatory Work

**Materials Required**

- Aurora100 or Aurora200
- Internet network
- Internet cable
- 4GB (or more memory) SD card and SD card reader
- PC (Windows10)
- [USB To Uart Adapter](https://www.seeedstudio.com/USB-To-Uart-5V%26amp%3B3V3-p-1832.html) (optional)
- 24V/2A DC interface adapter
- Multimeter
- Especial Speaker x 1  (Aurora100) or Especial Speaker x 2  (Aurora200)
- Especial Mic

**Uptdate firmware**

- **Step 1.** Select the [firmware](https://beagleboard.org/latest-images) to download and this firmware both Aurora 100 and Aurora 200 all be used:

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//firmware_link.png)

- **Step 2.** Connect an SD card to a PC or MAC with an SD card reader, an SD card with more than 4G memory is required.

- **Step 3.** Click here to download [Etcher](https://etcher.io/), then use the Etcher to write the  ```*.img.xz``` file directly to the SD card. Or extract the ```*.img.xz``` file into a ```*.img``` file, and then burn it to an SD card using another mirror write tool.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//etcher_burn_firmware.png)

we can get below the picture when the etcher burns successful.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//etcher_burn_firmware_complete.png)

- **Step 4.** After writing the image to the SD card, insert the SD card into Aurora.
<div STYLE="page-break-after: always;"></div>
For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/insert_SD_card_for100-1.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/insert_SD_card_for200.png)

- **Step 5.** Connect Aurora to a computer by using USB To Uart Adapter.the hardware connection as below.
<div STYLE="page-break-after: always;"></div>
|Aurora|USB To Uart Adapter|
|:----:|:------:|
|TX|RX|
|RX|TX|	
|GND|GND|

For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/UART_connection_100-1.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/UART_connection_200.png)

- **Step 6.** Connect RST to GND at stm8 to stop stm8 power-manager code.

>we can skip this step if use the newest firmware for stm8

For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/GND_TO_RST100.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/GND_TO_RST200.png)

the system will reboot repeatedly if our firmware does not have `power-manager.service`.and there does not exist `power-manager.service` at default firmware. So we have to connect RST to GND at stm8 to stop `power-manager.service   `. we will install the `power-manager.service` at subsequent steps.

- **Step 7.** Use [PUTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html), select `Serial` protocol, fill in the correct COM port of Aurora, 115200 baud, 8Bits, Parity None, Stop Bits 1, Flow Control None.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//COM_for_Aurora.png)

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//puttyh_login.png)

- **Step 8.** Use a 24V Power adapter to power the Aurora board. and you can see the LED power on. Do not take out the SD card during writing.

- **Step 9.** The login user name is `debian`, and password is `temppwd`.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//login_In_system.png)

- **Step 10.** Edit `/boot/uEnv.txt` then reboot to start eMMC boot.

```bash
sudo sh -c "echo cmdline=init=/opt/scripts/tools/eMMC/init-eMMC-\
flasher-v3.sh >> /boot/uEnv.txt"
sudo reboot
```

it will take some time for updating firmware.please wait with patience.
>You have to power off the board and unplug sd card when you terminal show this message.and the script will updating firmware repeatedly if we does not power off.Meanwhile,the four USER-LED will stop blinking and turn off  if the update successful.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//emmc_flash_succ.png)

- **Step 11.** Unplug `sd card` then power on.

If you boot at emmc , the terminal will print `/dev/mmcblk1p1`.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//emmc_boot.png)

- **Step 12.** Connect Internet cable to Ethernet interface if the Green LED to blink and the Yellow LED to light that indicates the network work well.we can get as below information about the eth0 at Aurora if we type `ifconfig` cmd.

```bash
ifconfig
```

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//ifconfig.png)

the ip addr maybe different for this picture depending on your router.

- **Step 13.** Internet test

```bash
ping -c 5 www.china.com
```

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//ping.png)

if the terminal print like this indicates the network has been connecting to the Internet.if we can not get the Internet maybe need to check your network environment.

### Devices Usage

**Env install**

- **Step 1.** git clone the test code.

```bash
cd ~
git clone --depth 1 https://github.com/Hansen0314/aurora_test.git
```

the aurora_test have below content.

|aurora test code|test aim|
|:----:|:------:|
|gpio|+12VS<br>Input<br>Relay<br>LED state|
|power-service|power manager|
|voice_card|Voice card|

- **Step 2.** Install the gpio to control the gpio of Aurora.

```bash
sudo cp ~/aurora_test/gpio /bin/
```

- **Step 3.** Install the power-service that communicate with stm8 to enable `power-manager.service`.

```bash
cd ~/aurora_test/power-service
sudo ./install.sh
```

and power-service folder has below file:

*1.STM8Firmware/power_manager.hex:* firmware for stm8 and how to update the firmware to stm8 you can view [Update STM8 firmware](#update-stm8-firmware)

*2.install. sh:* mpu-power-daemon.service install script. 

*3.mpu-power-daemon.service:* service config file for AM3358.

*4.power_manager.sh:* power manager script for AM3358.the more information you can access [power-manager](#power-manager).

you can disconnect GND to RST at stm8 for now.

- **Step 4.** Disable cloud9 service when next power on.

```bash 
sudo systemctl disable cloud9.socket
```

if everything well we can get information as below .

```bash 
debian@beaglebone:~$ sudo systemctl disable cloud9.socket
Removed /etc/systemd/system/sockets.target.wants/cloud9.socket.
```

- **Step 5.** Install voice card to enable speaker and mic then reboot.

```bash
sudo cp ~/aurora_test/BB-BONE-AUDI-02-00A0.dtbo /lib/firmware
sudo sh -c "echo uboot_overlay_addr0=/lib/firmware/BB-BONE-AUDI-02-\
00A0.dtbo >> /boot/uEnv.txt"
cd ~/aurora_test/voice_card
sudo cp asound.state /var/lib/alsa/
sudo cp asound.conf /etc/
sudo reboot
```

and voice_card folder has below file:

*1.asound.conf:* config ALSA.set the LEFT_LOP as output.and set LINE2R as input.
more information you can access [alsa](https://wiki.archlinux.org/index.php/Advanced_Linux_Sound_Architecture/Troubleshooting#Microphone).

*2.asound.state:* config voice card settings.make `aplay` and `arecord` work with the mono mode at default.  
more information you can access [alsa](https://wiki.archlinux.org/index.php/Advanced_Linux_Sound_Architecture/Troubleshooting#Microphone).

*3.open_Amplifier.sh:* open Amplifier.

*4.power_on_voice.sh:* power on voice then record and play.more information you can access  [Voice card of devices-usage](#devices-usage)

If the terminal prints no error go to next step.

**+12VS**

we can use this cmd to make +12VS power on.

```bash
gpio set 22
```

and the pin's location you can view the [Extern-Interface-pinout](#extern-interface-pinout).You can get 12v at +12VS by using a multimeter.

we can use this cmd to make +12VS power off.

```bash
gpio clear 22
```

**Input**

If you want to test input of aurora 100.

```bash
gpio input 44 #if GND connect to CALL we will get 0
gpio input 46 #if GND connect to SEN1 we will get 0
gpio input 87 #if the BUTTON be pressed we will get 0
```

if everything going well we will get this result.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/aurora100_input-2.png)

If you want to test input of aurora 200.

```bash
gpio input 44 #if GND connect to CALL we will get 0
gpio input 46 #if GND connect to SEN1 we will get 0
gpio input 87 #if the BUTTON be pressed we will get 0
gpio input 65 #if GND connect to SEN2 we will get 0
```

and the pin's location you can view the [Extern-Interface-pinout](#extern-interface-pinout).
the BUTTON's location we can view [hardware-view](#hardware-overview).

if everything going well we will get this result.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/aurora200_input-1.png)

and the pin's location you can view the [Extern-Interface-pinout](#extern-interface-pinout).

**LED state**

we can use this cmd to control the user-define LED.

```bash
gpio set 23 #power on LED
gpio clear 23 #power off LED
```

and the LED's location you can view [hardware-overview](#hardware-overview).

**Relay**

If you want to test relay of aurora 100 You can use this cmd.

```bash
gpio set 86 #make NO connect to GND
gpio clear 86 #make NO disconnect to GND
gpio set 47 #make NO-R connect to GND
gpio clear 47 #make NO-R disconnect to GND
```

If you want to test relay of aurora 200 You can use this cmd.

```bash
gpio set 86 #make NO connect to GND
gpio clear 86 #make NO disconnect to GND
gpio set 47 #make NO-R connect to COM
gpio clear 47 #make NO-R disconnect to COM
gpio set 27 #make NO-C connect to COM
gpio clear 27 #make NO-C disconnect to COM
```

maybe you need a multimeter to make sure the connection.

and the pin's location you can view [Extern-Interface-pinout](#extern-interface-pinout).

**Voice card**

the voice card needs some time to setup after power on. So we need to check voice card setup successful before run `./power_on_voice.sh`.we can use `aplay -l` to check whether set up successful. we can get this message if set up successful.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//aplay-l.png)

> and you can get this information as soon as login by using `root` login.

It is very important to check the connection of the Speaker and the Mic.and the pin's location you can view [Extern-Interface-pinout](#extern-interface-pinout).

|Mic|Aurora|
|:----:|:------:|
|Yellow|GND|
|Black|MIC-_M|
|Red|MIC+_M|

|Speaker|Aurora|
|:----:|:------:|
|Red|SPK+|
|Black|SPK-|
<div STYLE="page-break-after: always;"></div>
For Aurora100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/Speaker-Mic_connectionfor100.png)

For Aurora200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/Speaker-Mic_connectionfor200.png)


if you use aurora 100 we can use this cmd to test it.

```bash
cd ~/aurora_test/voice_card
./power_on_voice.sh 1
```

if you use aurora 200 we can use this cmd to test it.

```bash
cd ~/aurora_test/voice_card
./power_on_voice.sh 1 #the one speaker
./power_on_voice.sh 2 #the other speaker
``` 

you can hear your speech form the Speaker if you speak to the mic.and you can adjust the knob to modify the sound volume for hardware side.the software also supports adjust the sound volume by using `alsamixer`.

```bash 
sudo alsamixer
```

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//PCM.png)

The asound.conf and asound.state that you can found by accessing [github](https://github.com/Hansen0314/aurora_test/tree/master/voice_card).

## Appendix

### DDR3 speed test

- **Step 1.** install speed test tool

```bash
sudo apt update
sudo apt install -y mbw 
```
> if update failed we can use as below cmd to install ''mbw" 
<div STYLE="page-break-after: always;"></div>
```bash
cd ~
wget http://ftp.cn.debian.org/debian/pool/main/m/mbw/mbw_1.2.2-1+\
b1_armhf.deb
sudo dpkg -i mbw_1.2.2-1+b1_armhf.deb
```

- **Step 2.** test speed

```bash
mbw -q 100
```

we can get this message

```bash
AVG     Method: MEMCPY  Elapsed: 0.70637        MiB: 100.00000  Copy: 141.568 MiB/s
AVG     Method: DUMB    Elapsed: 0.54541        MiB: 100.00000  Copy: 183.347 MiB/s
AVG     Method: MCBLOCK Elapsed: 0.29263        MiB: 100.00000  Copy: 341.723 MiB/s
```

### EMMC speed test

- **Step 1.** clear caches

```bash
sudo sh -c "echo 3 > /proc/sys/vm/drop_caches"
```

- **Step 2.** test speed

```bash
time sudo dd if=/dev/mmcblk1 of=/dev/null bs=128k count=8192
```
we can get this message

```bash
8192+0 records in
8192+0 records out
1073741824 bytes (1.1 GB, 1.0 GiB) copied, 26.4425 s, 40.6 MB/s
```

### Power manager

Power manager have two-part on the one hand is stm8 and on the other hand, is AM3358.we have to use this cmd to enable stm8's power manager at AM3358 after power on the Aurora.and the location of stm8 and AM3358 we can view [hardware-overview](#hardware-overview).

```bash
gpio set 45
```

and this is content of power manager.The stm8 will send a message to AM3358 1.5min / time. if AM3358 cannot feedback to stm8, the stm8 will restart the AM3358.There exist a feedback code in our [GitHub](https://github.com/Hansen0314/aurora_test/blob/master/power-service/power_maneger.sh) for AM3358.

>If the power manager power on at stm8, at the same time the AM3358's power manager has to enable. how to enable it we can view [Env install](#devices-usage)'s step4.

We need to generate the falling edge level at AM3358 if you want to power off the stm8's power manager.

```bash
gpio set 45
gpio clear 45
```

### Make dtbo file 

```bash
cd ~
git clone https://github.com/Seeed-Studio/seeed-linux-dtoverlays.git
cd ~/seeed-linux-dtoverlays
make all_bb 
sudo make install_bb
```

if everything works fine we can get the below message.

```bash
debian@beaglebone:~/seeed-linux-dtoverlays$ make all_bb
  DTC     overlays/bb/BB-I2C2-SHT3X.dtbo
  DTC     overlays/bb/BB-I2C1-BME280.dtbo
  DTC     overlays/bb/BB-GPIO-P9813.dtbo
  DTC     overlays/bb/PB-I2C1-TLV320AIC3104.dtbo
  DTC     overlays/bb/BB-I2C2-MPR121.dtbo
  DTC     overlays/bb/BB-I2C2-LIS331DLH.dtbo
  DTC     overlays/bb/BB-GPIO-GROVE-BUTTON.dtbo
  DTC     overlays/bb/BB-UART4-E-INK.dtbo
  DTC     overlays/bb/BB-I2C1-JHD1802.dtbo
  DTC     overlays/bb/BB-BONE-AUDI-02-00A0.dtbo
  DTC     overlays/bb/BB-I2C2-VL53L0X.dtbo
  DTC     overlays/bb/BB-GPIO-GROVE-LED.dtbo
  DTC     overlays/bb/BB-GPIO-HCSR04.dtbo
  DTC     overlays/bb/BB-I2C2-ADXL34X.dtbo
  DTC     overlays/bb/BB-I2C1-ADXL34X.dtbo
make[1]: *** /lib/modules/4.19.94-ti-r42/build: No such file or directory.  Stop.
make: *** [Makefile:151: all_bb] Error 2
debian@beaglebone:~/seeed-linux-dtoverlays$ sudo make install_bb
mkdir -p /lib/firmware/
cp -v overlays/bb/*.dtbo /lib/firmware/
'overlays/bb/BB-BONE-AUDI-02-00A0.dtbo' -> '/lib/firmware/BB-BONE-AUDI-02-00A0.dtbo'
'overlays/bb/BB-GPIO-GROVE-BUTTON.dtbo' -> '/lib/firmware/BB-GPIO-GROVE-BUTTON.dtbo'
'overlays/bb/BB-GPIO-GROVE-LED.dtbo' -> '/lib/firmware/BB-GPIO-GROVE-LED.dtbo'
'overlays/bb/BB-GPIO-HCSR04.dtbo' -> '/lib/firmware/BB-GPIO-HCSR04.dtbo'
'overlays/bb/BB-GPIO-P9813.dtbo' -> '/lib/firmware/BB-GPIO-P9813.dtbo'
'overlays/bb/BB-I2C1-ADXL34X.dtbo' -> '/lib/firmware/BB-I2C1-ADXL34X.dtbo'
'overlays/bb/BB-I2C1-BME280.dtbo' -> '/lib/firmware/BB-I2C1-BME280.dtbo'
'overlays/bb/BB-I2C1-JHD1802.dtbo' -> '/lib/firmware/BB-I2C1-JHD1802.dtbo'
'overlays/bb/BB-I2C2-ADXL34X.dtbo' -> '/lib/firmware/BB-I2C2-ADXL34X.dtbo'
'overlays/bb/BB-I2C2-LIS331DLH.dtbo' -> '/lib/firmware/BB-I2C2-LIS331DLH.dtbo'
'overlays/bb/BB-I2C2-MPR121.dtbo' -> '/lib/firmware/BB-I2C2-MPR121.dtbo'
'overlays/bb/BB-I2C2-SHT3X.dtbo' -> '/lib/firmware/BB-I2C2-SHT3X.dtbo'
'overlays/bb/BB-I2C2-VL53L0X.dtbo' -> '/lib/firmware/BB-I2C2-VL53L0X.dtbo'
'overlays/bb/BB-UART4-E-INK.dtbo' -> '/lib/firmware/BB-UART4-E-INK.dtbo'
'overlays/bb/PB-I2C1-TLV320AIC3104.dtbo' -> '/lib/firmware/PB-I2C1-TLV320AIC3104.dtbo'
mkdir -p /lib/modules/4.19.94-ti-r42/extra/seeed || true
cp: cannot stat '/home/debian/seeed-linux-dtoverlays/modules/e-ink/*.ko': No such file or directory
make: *** [Makefile:161: install_bb] Error 1
```

### Update STM8 firmware

- **Step 1.** Download [stvp](https://drive.google.com/file/d/1hm5hKK_gqNOe6aBj4hlX1Di66oHQber4/view?usp=sharing) that is a download tool for stm8.

- **Step 2.** Install stm8 [driver](https://drive.google.com/file/d/1muwNTGqqdtcXkhjUn50fcBhIeQV_bj-O/view?usp=sharing).

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//stlink_driver_install.png)


- **Step 3.** Open the stvp and config it.

Select `ST-Link ->SWIM->STM8S00F3`
![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//stvp_select_stm8.png)

- **Step 4.** dowmload [firmware](https://raw.githubusercontent.com/Hansen0314/aurora_test/master/power-service/STM8Firmware/power_manager.hex) to desktop and rename to `power_manager.hex`.

- **Step 5.**  Power off the aurora by using power switch.

- **Step 6.**  Connect STM8's SWIM interface to the computer by using ST-link.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/SWIM_CONNECTION.png)

the `SWIM interface`'s location you can view [hardware-overview](#hardware-overview).

- **Step 7.** Open the firmware then burn it to stm8

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//stvp_Open.png)

burn the firmware

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//burn_firmware.png)

>if get some error when burning you can replug the st-link to the computer.

if we burn successful we can get below picture.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/burn-successful.png)

