
SERVER="example.com"
LOG_FILE="/path/to/uptime.log"
check_server_status() {
    if ping -c 1 -W 1 "$SERVER" > /dev/null 2>&1; then
        echo "$(date '+%Y-%m-%d %H:%M:%S') - $SERVER is UP" >> "$LOG_FILE"
    else
        echo "$(date '+%Y-%m-%d %H:%M:%S') - $SERVER is DOWN" >> "$LOG_FILE"
    fi
}
while true; do
    check_server_status
    sleep 60
done
