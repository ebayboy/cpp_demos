#!/bin/bash -
#===============================================================================
#
#          FILE: build.sh
#
#         USAGE: ./build.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2020年09月13日 20时32分20秒
#      REVISION:  ---
#===============================================================================

if [ "$1" == "clean" ]; then
	echo "clean..."
	rm  -rf y.tab.h.gch token.tab.c  lex.yy.c
	exit 1
fi
echo "build..."

flex token.l

#会得到文件：lex.yy.c

#运行命令：
bison -t -v -d token.y 

#运行命令：
cc *.c

#会得到文件 a.out
