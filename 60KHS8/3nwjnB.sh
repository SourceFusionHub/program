#!/bin/bash

# Output file for DNS query logs
LOG_FILE="/var/log/dns_queries.log"

# Function to log DNS queries
log_dns_query() {
    echo "[$(date)] DNS Query: $1" >> "$LOG_FILE"
}

# Start capturing DNS traffic using tcpdump
tcpdump -i eth0 -n -s 0 -v 'udp port 53' | while read -r line; do
    # Check if the line contains a DNS query
    if echo "$line" | grep -q "A\?"; then
        query=$(echo "$line" | awk '{print $NF}')
        log_dns_query "$query"
    fi
done
