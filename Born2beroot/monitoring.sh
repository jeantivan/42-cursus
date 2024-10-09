#!/bin/bash

#Architecture
ARC=$(uname -v)

#CPU Physical
CPU=$(grep "physical id" /proc/cpuinfo | wc -l)

#CPU Virtual
vCPU=$(grep processor /proc/cpuinfo | wc -l)

# USED RAM 
RAM_TOT=$(free --mega | awk '$1 == "Mem:" {print $3}')

#TOTAL RAM
RAM_TOT=$(free --mega | awk '$1 == "Mem:" {print $2}')

# % RAM used
POR_RAM_USED=$(free --mega | awk '$1 == "Mem:" {printf("%.2f%%", $3/$2*100)}')

# Disk Used
DISK_USED=$(df -m | grep "/dev" | grep -v "/boot" | awk '{mem_use += $3} END {print mem_use}')

# Disk Total
DISK_TOT=$(df -m | grep "/dev" | grep -v "/boot" | awk '{mem_tot += $2} END {printf("%.0Gb", mem_tot/1024)}')

# % Disk used
POR_DISK_USED=$(df -m | grep "/dev" | grep -v "/boot" | awk '{used += $3} {tot += $2} END {printf("(%d%%)", used/tot*100)}')

# % CPU Used
CPU_USED=$(vmstat 1 4 | tail -1 | awk '{print $15}')

# Last reboot
LAST_REBOOT=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# Use LVM
USE_LVM=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP Connections
TCP_CON=$(ss -ta | grep ESTAB | wc -l)

# Num user
N_USERS=$(users | wc -w)

# Ip address
IP_ADDRESS=$(hostname -I)

#MAC address
MAC_ADDRESS=$(ip link | grep "link/ether" | awk '{print $2}')

# Num command eject with sudo
N_SUDO_COMMAND=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "  #Architecture: $ARC
        #CPU (physical): $CPU        
        #vCPU: $VCPU
        #Memory Usage: $RAM_USED/$RAM_TOT ($POR_RAM_USED)
        #Disk Usage: $DISK_USED/$DISK_TOT ($POR_DISK_USED)
        #CPU Load: 
        #Last boot: $LAST_REBOOT
        #LVM use: $USE_LVM
        #TCP Connections: $TCP_CON ESTABLISHED
        #User log: $N_USERS
        #Network: IP $IP_ADDRESS ($MAC_ADDRESS)
        #Sudo: $N_SUDO_COMMAND cmd"