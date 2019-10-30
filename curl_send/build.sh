#!/bin/bash


g++ -DDEBUG -g -o send_request  send_request.cpp -lcurl -I./include/ -L./lib/ || exit 1

./send_request || exit 1

ls -alF *.json
md5sum *.json
