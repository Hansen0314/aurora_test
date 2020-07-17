# Aurora Software Guide

This software provide some shell commands to demo how to drive devices on the Aurora Device.

## Specification

For Aurora 100
|Item|Values|
|----|------|
|Memory|512MB DDR3 RAM|
|Storage| 4GB 8-bit eMMC on-board flash<br>SD slot|	
|Peripheral Interface| 1 x USB Host<br>1 x 100M Ethernet interface<br>1 x Record interface<br>1 x Play interface<br>2 x Relay output interface(MAX 30V/2A))<br>2 x GPIO input interface<br>1 x Extern 12V interface(MAX 2A)<br>1 x USB OTG<br>1 x SD card interface <br>1 x TTL UART|
|On-board LED|1 x Power LED<br>1 x user-defined LED|
|Power|1 x DC interface (24V/2.5A)|
|Button|1 x reset button|
|Knob|1 x sound volume knob|
|Operating temperature(C) | 0 ~ 90 (refer to [am3358](https://www.ti.com/product/AM3358))|

For Aurora 200

|Item|Values|
|----|------|
|Memory|512MB DDR3 RAM|
|Storage| 4GB 8-bit eMMC on-board flashsud<br>SD slot|	
|Peripheral Interface| 1 x USB Host<br>4 x 100M Ethernet interface<br>1 x Record interface<br>2 x Play interface<br>3 x Relay output interface(MAX 30V/2A)<br>3 x GPIO input interface<br>1 x Extern 12V interface(MAX 2A)<br>1 x USB OTG<br>1 x SD card interface <br>1 x TTL UART|
|On-board LED|1 x Power LED<br>1 x User-defined LED<br>1 x Network status LED|
|Power|1 x DC interface(24V/2.5A)|
|Button|1 x Reset button|
|Knob|1 x Sound volume knob|
|Operating temperature(C) | 0 ~ 90 (refer to [am3358](https://www.ti.com/product/AM3358))|

## Hardware Overview 

It is convenient to use this hardware overview for finding the location of the hardware.

For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//aurora100.png)

- **1. LED:** Include power LED and user-defined LED.

- **2. USB OTG:** This USB Port is used to connect to your computer via serial mode of putty.

- **3. USB Host:** You can plug USB device, such as USB mouse,USB keyboard and USB flash disk into Aurora via those two USB hosts.

- **4. Ethernet interface:** Access to the Internet.

- **5. Extern Interface:** Include 1 x Record interface , 1 x Play interface , 2 x Relay output interface , 2 x GPIO input interface , 1 x Extern 12V interface.

- **6. Knob:** Adjust the speaker volume.

- **7. Power switch:** Power on or power off the Aurora.

- **8. DC jack:** Input 24V/2.5A power.

- **9. TTL UART:** You also can connect the Aurora with your computer via this UART port.

- **10. SWIM jack:** You can use this jack to update the mpu(stm8) firmware.

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

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//aurora200.png)

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

- **11. SWIM jack:** You can use this jack to update the mpu(stm8) firmware.

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

- **22. Power button:** power on or power off the AM3358.

## Extern Interface pinout

It is very useful when we test there pin.

For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//100_Extern_Interface_pinout.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//200_Extern_Interface_pinout.png)

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

For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//insert_SD_card_for100.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//insert_SD_card_for200.png)

- **Step 5.** Connect Aurora to a computer by using USB To Uart Adapter.the hardware connection as below.

|Aurora|USB To Uart Adapter|
|:----:|:------:|
|TX|RX|
|RX|TX|	
|GND|GND|

For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//UART_connection_100.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//UART_connection_200.png)

- **Step 6.** Connect RST to GND at stm8 to stop stm8 power-manager code.
For Aurora 100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//GND_TO_RST100.png)

For Aurora 200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//GND_TO_RST200.png)

the system will reboot repeatedly if our firmware does not have `power-manager.service`.and there does not exist `power-manager.service` at default firmware. So we have to connect RST to GND at stm8 to stop `power-manager.service   `. we will install the `power-manager.service` at subsequent steps.

- **Step 7.** Use [PUTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html), select `Serial` protocol, fill in the correct COM port of Aurora, 115200 baud, 8Bits, Parity None, Stop Bits 1, Flow Control None.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//COM_for_Aurora.png)

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//puttyh_login.png)

- **Step 8.** Use a 24V Power adapter to power the Aurora board. and you can see the LED power on. Do not take out the SD card during writing.

- **Step 9.** The login user name is `debian`, and password is `temppwd`.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//login_In_system.png)

- **Step 10.** Edit `/boot/uEnv.txt` then reboot to start eMMC boot.

```bash
sudo sh -c "echo cmdline=init=/opt/scripts/tools/eMMC/init-eMMC-flasher-v3.sh >> \ /boot/uEnv.txt"
sudo reboot
```

it will take some time for updating firmware.please wait with patience.
>You have to power off the board and unplug sd card when you terminal show this message.and the script will updating firmware repeatedly if we does not power off.

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

- **Step 2.** Install the gpio to control the gpio of Aurora.

```bash
sudo cp ~/aurora_test/gpio /bin/
```

- **Step 3.** Install the phytool to config the LAN of Aurora.

```bash
git clone  https://github.com/wkz/phytool
cd ~/phytool
make
sudo make install
sudo cp /usr/local/bin/phytool /home/debian/aurora_test/eth0/
```

- **Step 4.** Install the power-service that communicate 
with stm8 to enable `power-manager.service`.

```bash
cd ~/aurora_test/power-service
sudo ./install.sh
```

you can disconnect GND to RST at stm8 for now.

- **Step 5.** Install voice card to enable speaker and mic then reboot.

```bash
sudo sh -c "echo uboot_overlay_addr0=/lib/firmware/BB-BONE-AUDI-02-00A0.dtbo >> \ /boot/uEnv.txt"
cd ~/aurora_test/voice_card
sudo cp asound.state /var/lib/alsa/
sudo cp asound.conf /etc/
sudo reboot
```

If the terminal prints no error go to next step.

**12+V**

we can use this cmd to make 12v power on.

```bash
gpio set 11
```

You can get 12v at J54(aurora 100)-pin4 or J21(aurora 200)-pin1 by using a multimeter.and the pin's location you can view the [Extern-Interface-pinout](https://github.com/Hansen0314/aurora_test#extern-interface-pinout).

we can use this cmd to make 12v power off.

```bash
gpio clear 11
```

**Input**

If you want to test input of aurora 100.

```bash
gpio input 44 #if GND connect to CALL we will get 1
gpio input 46 #if GND connect to SENSOR#1 we will get 1
gpio input 75 #if GND connect to Small_hole we will get 1
```

if everything going well we will get this result.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/aurora100_input.png)

If you want to test input of aurora 200.

```bash
gpio input 44 #if GND connect to CALL we will get 0
gpio input 46 #if GND connect to SENSOR#1 we will get 0
gpio input 75 #if GND connect to Small_hole we will get 1
gpio input 65 #if GND connect to SENSOR#2 we will get 0
```

if everything going well we will get this result.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/aurora200_input.png)

and the pin's location you can view the [Extern-Interface-pinout](https://github.com/Hansen0314/aurora_test#extern-interface-pinout).

this is Small_hole's location for Aurora100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//ext_sen_for100.png)

this is Small_hole's location for Aurora200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//ext_sen_for200.png)

**LED state**

we can use this cmd to control the user-define LED.

```bash
gpio set 23 #power on LED
gpio clear 23 #power off LED
```

and the LED's location you can view [hardware-overview](https://github.com/Hansen0314/aurora_test#hardware-overview).

**Relay**

If you want to test relay of aurora 100 You can use this cmd.

```bash
gpio set 71 #make NO connect to GND
gpio clear 71 #make NO disconnect to GND
gpio set 47 #make NO-R connect to GND
gpio clear 47 #make NO-R disconnect to GND
```

If you want to test relay of aurora 200 You can use this cmd.

```bash
gpio set 71 #make NO connect to GND
gpio clear 71 #make NO disconnect to GND
gpio set 47 #make NO-R connect to GND
gpio clear 47 #make NO-R disconnect to GND
gpio set 27 #make NO-C connect to GND
gpio clear 27 #make NO-C disconnect to GND
```

and the pin's location you can view [Extern-Interface-pinout](https://github.com/Hansen0314/aurora_test#extern-interface-pinout).

**Voice card**

the voice card needs some time to setup after power on. So we need to check voice card setup successful before run `./power_on_voice.sh`.we can use `aplay -l` to check whether set up successful. we can get this message if set up successful.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//aplay-l.png)

> and you can get this information as soon as login by using `root` login.

It is very important to check the connection of the Speaker and the Mic.and the pin's location you can view [Extern-Interface-pinout](https://github.com/Hansen0314/aurora_test#extern-interface-pinout).

|Mic|Aurora|
|:----:|:------:|
|Yellow|GND|
|Black|MIC-_M|
|Red|MIC+_M|

|Speaker|Aurora|
|:----:|:------:|
|Red|SPK+|
|Black|SPK-|

For Aurora100

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//Speaker-Mic_connectionfor100.png)

For Aurora200

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//Speaker-Mic_connectionfor200.png)


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

**Update STM8 firmware**

- **Step 1.** Download [stvp](https://drive.google.com/file/d/1hm5hKK_gqNOe6aBj4hlX1Di66oHQber4/view?usp=sharing) that is a download tool for stm8.

- **Step 2.** Install stm8 [driver](https://drive.google.com/file/d/1muwNTGqqdtcXkhjUn50fcBhIeQV_bj-O/view?usp=sharing).

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//stlink_driver_install.png)


- **Step 3.** Open the stvp and config it.

Select `ST-Link ->SWIM->STM8S00F3`
![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//stvp_select_stm8.png)

- **Step 4.** dowmload [firmware](https://raw.githubusercontent.com/Hansen0314/aurora_test/master/power-service/STM8Firmware/power_manager.hex) to desktop and rename to `power_manager.hex`.

- **Step 5.**  Connect STM8 to the computer by ST-link

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//SWIM_CONNECTION.png)

- **Step 6.** Open the firmware then burn it to stm8

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//stvp_Open.png)

burn the firmware

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img//burn_firmware.png)

if we burn successful we can get below picture.

![](https://raw.githubusercontent.com/Hansen0314/aurora_img/master/img/burn-successful.png)

## Appendix

### DDR3 speed test

- **Step 1.** install speed test tool

```bash
sudo apt update 
sudo apt install -y mbw 
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