## clearlog.py
Clears /var/log/syslog file periodically.
Used when having infinite loop bug, deadlock situtaion, fifo module permission issues as running these fills syslog very fast.

## killopensips.sh
Kills all leftover opensips running processes.
In case of bugs opensips keeps running in backgrounds fills up process.
