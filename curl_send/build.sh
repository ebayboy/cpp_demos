#!/bin/bash

g++ -DDEBUG -g -o send_request  *.cpp -lcurl -I./include/ -L./lib/ || exit 1

