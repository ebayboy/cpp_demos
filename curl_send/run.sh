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

cat output.json | jq . > fmt.json || exit 1
rm output.json && ls -alF *.json

OUTTXT=fmt_req.txt
PREV_LINES=`cat $OUTTXT | wc -l`	

SIZE=`jq .size fmt.json`
for ((i=0; i<$SIZE;i++))
do
	jq .data[$i].request_uri fmt.json >> $OUTTXT
done

SUFF_LINES=`cat $OUTTXT | wc -l`	

echo "PREV_LINES:$PREV_LINES SUFF_LINES:$SUFF_LINES"

exit 0

