####################################
# Script to start 
# vcan
####################################
# Make the bash program executable
# by +x (adding execute permission to all)
# chmod +x vcan_start.sh
####################################
#!/bin/bash

# Set the name og the can port
CAN_PORT="can0"

echo "$CAN_PORT started"

# Start vcan
sudo modprobe vcan
# add and set up dev with name CAN_PORT
sudo ip link add dev $CAN_PORT type vcan
sudo ip link set up $CAN_PORT

