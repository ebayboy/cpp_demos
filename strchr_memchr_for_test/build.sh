#!/bin/bash

g++ -O2 -o for for.c
g++ -O2 -o strchr strchr.c
g++ -O2 -o memchr memchr.c


echo "for cost:"
time ./for 
sleep 1

echo "strchr cost:"
time ./strchr
sleep 1

echo "memchr cost:"
time ./memchr 
