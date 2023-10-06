# !/bin/bash

# To set the threshold for system load average (here it is shown as 2)
threshold=2.0

# To get the 1-minute load average using uptime
load_average=$(uptime | awk -F'[ ,]' '{print $(NF-2)}')

# To compare the load average with the threshold
if (( $(echo "$load_average > $threshold" | bc -l) )); then
    # System load is higher than the threshold, send an alert
    subject="System Load Alert"
    message="System load is high. Current load average: $load_average"

    # We should replace user@example.com with the actual email address
    recipient="user@example.com"

    # To send email alert using the mail command
    echo "$message" | mail -s "$subject" "$recipient"
fi

# To run the script on regular interval using cron

*/5 * * * * /path/to/your/script.sh
