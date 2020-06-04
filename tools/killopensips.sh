#!/bin/bash
ps aux | grep "opensips -f" | awk '$1=="root" {print $2}' | paste -sd" " | xargs sudo kill -SIGKILL

# opensips stop doesn't work
