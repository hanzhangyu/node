#!/usr/bin/env bash
set -x

if [[ -n "$1" ]]
then
  echo $1
fi
echo "start run.sh"
sleep 10s
echo "end run.sh"
exit 1
