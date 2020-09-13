i
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

set -o nounset                                  # Treat unset variables as an error

flex token.l

#会得到文件：lex.yy.c

#运行命令：
bison token.y

#会得到文件： 
token.tab.c

#运行命令：
gcc *

#会得到文件 a.out
#rm  -rf y.tab.h.gch token.tab.c  lex.yy.c
