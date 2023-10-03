#!/bin/bash

# Set variables
INTERFACE="eth0"
THRESHOLD=1000

# Function to analyze network traffic
analyze_traffic() {
    local interface=$1
    local threshold=$2

    # Get the current number of packets
    current_packets=$(cat /proc/net/dev | grep $interface | awk '{print $2}')

    # Get the previous number of packets
    previous_packets=$(cat /proc/net/dev | grep $interface | awk '{print $3}')

    # Calculate the difference between the current and previous number of packets
    packet_diff=$((current_packets - previous_packets))

    # Check if the difference exceeds the threshold
    if [ $packet_diff -gt $threshold ]; then
        echo "Possible network intrusion detected. Packet difference: $packet_diff"
        mitigate_intrusion
    else
        echo "No network intrusion detected. Packet difference: $packet_diff"
    fi
}

# Function to mitigate network intrusion
mitigate_intrusion() {
    echo "Mitigating network intrusion..."

    # Block all incoming traffic
    iptables -A INPUT -j DROP

    # Notify the system administrator
    echo "Possible network intrusion detected. Blocking all incoming traffic." | mail -s "Network Intrusion Alert" sysadmin@example.com
}

# Main loop
while true; do
    analyze_traffic $INTERFACE $THRESHOLD
    sleep 10
done
