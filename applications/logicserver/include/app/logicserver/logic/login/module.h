/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id module.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/19 19:09
 * @uses The login logic module class.
*/
#ifndef APP_LOGICSERVER_LOGIC_LOGIN_MODULE_H_
#define APP_LOGICSERVER_LOGIC_LOGIN_MODULE_H_

#include "app/logicserver/logic/config.h"

namespace logic {

class LoginModule : public pf_plugin::logic::contracts::Module {

 public:
   LoginModule(pf_plugin::logic::contracts::Kernel *logic) :
    pf_plugin::logic::contracts::Module(logic) {};
   ~LoginModule() {};

 public:
   void print() { std::cout << "LoginModule" << std::endl; }

};

}; //namespace logic

#endif //APP_LOGICSERVER_LOGIC_LOGIN_MODULE_H_
