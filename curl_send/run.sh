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
	echo "Usage: $0 date times $#"
	exit 1
fi

rm -rf $1 && mkdir $1 && cd $1

../send_request $1 $2

#cat output.json | jq . > fmt.json || exit 1

#OUTTXT=fmt_req.txt

SIZE=`jq .size fmt.json`
for ((i=0; i<$SIZE;i++))
do
	jq .data[$i].request_uri fmt.json >> $OUTTXT
done

exit 0

