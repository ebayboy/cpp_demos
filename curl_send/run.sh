#!/bin/bash

# ***************************************************************************
# * 
# * @file:run.sh 
# * @author:ebayboy@163.com 
# * @date:2019-10-30 16:15 
# * @version 1.0  
# * @description: Shell script 
# * @Copyright (c)  all right reserved 
#* 
#**************************************************************************/ 

./send_request || exit 1

cat output.json | jq . > fmt.json

rm output.json

ls -alF *.json

exit 0

