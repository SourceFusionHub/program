#!/bin/bash

# Set the log file path
LOG_FILE=/var/log/syslog

# Set the email address to send alerts to
EMAIL_ADDRESS=admin@example.com

# Set the time interval for checking the logs (in seconds)
TIME_INTERVAL=300

# Loop indefinitely
while true; do
    # Get the last line of the log file
    LAST_LINE=$(tail -n 1 $LOG_FILE)

    # Check if the last line contains any suspicious activity
    if [[ $LAST_LINE == *"suspicious activity"* ]]; then
        # Send an email alert
        echo "Suspicious activity detected: $LAST_LINE" | mail -s "Security Incident Alert" $EMAIL_ADDRESS
    fi

    # Wait for the specified time interval before checking again
    sleep $TIME_INTERVAL
done
