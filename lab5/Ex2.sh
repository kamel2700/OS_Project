#!/bin/bash

while true
do


	if ! ln Ex2.txt Ex2.txt.lock ; then
		End=$(tail-n 1 Ex2.txt.lock)
		printf "$((End + 1))\n" >> Ex2.txt.lock
		rm Ex2.txt.lock
	fi
done
