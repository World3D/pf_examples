#!/bin/sh
times=0
i=1
while ((i<=1))
do

for ((integer = 1; integer <= 100; integer++)) 
do
  ./client --daemon
done

ps aux | grep client --daemon | awk '{print $2}' | xargs kill -9

((times += 100))
echo "now times: "$times

sleep 1

done
