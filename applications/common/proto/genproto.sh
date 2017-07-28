#!/bin/sh
#the The proto generateor shell script.
#@version 1.0
#@author viticm<viticm.ti@gmail.com>
#@date 2017-07-12

protocargs="
--cpp_out=\"./src/\"
"

curdir=`pwd`
subdir=`echo $0 | sed 's;genproto.sh;;g'`
bindir=$curdir
[[ $subdir != "./" && $subdir != "/" ]] && bindir=$curdir/$subdir
[[ $curdir != $bindir ]] && echo "Enter dir: "$bindir
cd $bindir
protofiles=`find ./game/*.proto`
mkdir -p "./src"

for file in $protofiles 
do
  cmd="protoc $protocargs $file"
  echo $cmd && eval $cmd
done
echo "Leave dir: "$bindir
[[ $curdir != $bindir ]] && cd $curdir
