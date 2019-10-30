#!/bin/bash


g++ -DDEBUG -g -o send_request  send_request.cpp -lcurl -I./include/ -L./lib/ || exit 1

./send_request || exit 1


cat output.json | jq . > fmt.json

rm output.json

ls -alF *.json
