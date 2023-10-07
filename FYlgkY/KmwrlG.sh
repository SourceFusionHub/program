#!/bin/bash


LOG_FILE=/var/log/login_attempts.log

tail -f /var/log/system.log | while read LINE; do
    # Check if the line contains a login attempt
    if echo "$LINE" | grep -q "authentication succeeded"; then
        USERNAME=$(echo "$LINE" | awk '{print $9}')
        echo "$(date) - $USERNAME logged in" >> $LOG_FILE
    fi
done
