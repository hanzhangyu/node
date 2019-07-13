#!/usr/bin/env bash
set -e
cd playground/child_process/orphan

./child.sh &
pid=$!
echo "child pid is: ${pid}"
sleep 5 # 5秒钟之后父进程死亡，将子进程交付给 init 进程 ( we are free! )
echo "bye parent"
exit 0
