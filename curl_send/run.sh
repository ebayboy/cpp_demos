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

if (($# < 2));then
	echo "Usage: $0 date_from date_to $#"
	exit 1
fi

mkdir run_log && cd run_log

../send_request "$1" "$2"

