#!/bin/bash

current_user=`whoami`
systembit=`getconf LONG_BIT`
current_dir=`pwd`
sudo_str=""

#help text, the script desc
#@param void
#@return void
function help_text() {
  cat <<EOF
${0} ver 1.0

options:
--protobuf      install protobuf in your system
--help          view the text, or just use -h
--full          intall unix odbc and mysql odbc driver
EOF
}

#print error message, red words
#@param string message
#@return void
function error_message() {
  local message=${1}
  echo -e "\e[0;31;1merror: ${message}\e[0m"
  exit 1
}

#print warning message, yellow words
#@param message
#@return string void
function warning_message() {
  local message=${1}
  echo -e "\e[0;33;1mwarning: ${message}\e[0m"
}

#print success message, yellow words
#@param message
#@return string void
function success_message() {
  local message=${1}
  echo -e "\e[0;32;1msuccess: ${message}\e[0m"
}

function check_privileges() {
  if [[ $current_user != "root" ]] ; then
    error_message "run this script need root privileges"  
  fi
}

#install protobuf
#@param void
#@return void
function install_protobuf() {
  cd $current_dir
  chmod +x ./bin/*
  cp ./bin/* /usr/local/bin/ -r
  cp ./lib/* /usr/local/lib/ -r
  cp ./include/* /usr/local/include/ -r
  [[ 0 == $? ]] && success_message "install protobuf complete"
}

#the script main function, like c/c++
function main() {
  cmd=${1}
  cmd1=${2}
  if [[ "--sudo" == $cmd1 ]] ; then
    sudo_str="sudo"
  else
    check_privileges
  fi
  case "${cmd}" in
    --help ) help_text;;
    -h) help_text;;
    --protobuf) install_protobuf;;
    --full) install_protobuf;;
  esac
}
if [[ "" == ${@} ]] ; then
  error_message "${0}: no commond specified.You can use <${0} --help> "
                "get parameters for this script."
else
  main "${@}"
  exit 0
fi
