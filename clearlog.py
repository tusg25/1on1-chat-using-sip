#!/usr/bin/python
from subprocess import Popen, PIPE
from shlex import split
import time

while True:
	p1 = Popen(split("ls -lh /var/log/syslog"),stdout=PIPE)
	p2 = Popen(split("awk '{print $5}'"),stdin=p1.stdout,stdout=PIPE)
	output, error = p2.communicate()
	# print(str(output)[2:-3])
	if 'G' in str(output):
		p = Popen(split("sudo truncate -s 0 /var/log/syslog"),stdout=PIPE)
	time.sleep(100)

### Empties log every 100 second : was used for deadlock bug of utimer 