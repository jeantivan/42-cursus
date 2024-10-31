#!/bin/bash

#Architecture
ARC=$(uname -v)

#CPU Physical
CPU=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)

#CPU Virtual
vCPU=$(grep "^processor" /proc/cpuinfo | wc -l)

# USED RAM 
RAM_USED=$(free --mega | awk '$1 == "Mem:" {print $3}')

#TOTAL RAM
RAM_TOT=$(free --mega | awk '$1 == "Mem:" {printf("%d"), $2}')

# % RAM used
POR_RAM_USED=$(free --mega | awk '$1 == "Mem:" {printf("%.2f%%"),  $3/$2*100}')

# DISK TOTAL
DISK_TOT=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{dt += $2} END {printf ("%.1fGb\n"), dt/1024}')

#DISK_USED
DISK_USED=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{du += $3} END {print du}')

#PERCENT DISK USED
POR_DISK_USED=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{du += $3} {dt+= $2} END {printf("%d"), du/dt*100}')

# % CPU Used
CPU_LOAD=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')

# Last reboot
LAST_REBOOT=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# Use LVM
USE_LVM=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP Connections
TCP_CON=$(ss -ta | grep ESTAB | wc -l)

# Num user
N_USERS=$(users | wc -w)

# Ip address
IP_ADDRESS=$(hostname  -I | awk '{print $1}')

#MAC address
MAC_ADDRESS=$(ip link | grep "link/ether" | awk '{print $2}')

# Num command eject with sudo
N_SUDO_COMMAND=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall -n "        #Architecture: $ARC
        #CPU (physical): $CPU        
        #vCPU: $vCPU
        #Memory Usage: $RAM_USED/${RAM_TOT}MB ($POR_RAM_USED)
        #Disk Usage: $DISK_USED/${DISK_TOT} ($POR_DISK_USED%)
        #CPU Load: $CPU_LOAD
        #Last boot: $LAST_REBOOT
        #LVM use: $USE_LVM
        #TCP Connections: $TCP_CON ESTABLISHED
        #User log: $N_USERS
        #Network: IP $IP_ADDRESS ($MAC_ADDRESS)
        #Sudo: $N_SUDO_COMMAND cmd"
