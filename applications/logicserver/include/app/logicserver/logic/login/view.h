/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id view.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/19 19:12
 * @uses The login logic view class.
*/
#ifndef APP_LOGICSERVER_LOGIC_LOGIN_VIEW_H_
#define APP_LOGICSERVER_LOGIC_LOGIN_VIEW_H_

#include "app/logicserver/logic/config.h"

namespace logic {

class LoginView : public pf_plugin::logic::contracts::View {

 public:
   LoginView(pf_plugin::logic::contracts::Kernel *logic) :
    pf_plugin::logic::contracts::View(logic) {}
   virtual ~LoginView() {}

 public:
   virtual bool make(int32_t, void *) { return false; };

 public:
   void print() { std::cout << "LoginView" << std::endl; }

};

}; //namespace logic

#endif //APP_LOGICSERVER_LOGIC_LOGIN_VIEW_H_
