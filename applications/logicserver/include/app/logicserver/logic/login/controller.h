/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id controller.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/19 18:59
 * @uses The login logic controller.
*/
#ifndef APP_LOGICSERVER_LOGIC_LOGIN_CONTROLLER_H_
#define APP_LOGICSERVER_LOGIC_LOGIN_CONTROLLER_H_

#include "app/logicserver/logic/config.h"

namespace logic {

class LoginController : public pf_plugin::logic::contracts::Controller {

 public:
   LoginController(pf_plugin::logic::contracts::Kernel *logic) : 
    pf_plugin::logic::contracts::Controller(logic) {};
   virtual ~LoginController() {}

 public:
   virtual bool setuplayout();
   virtual int32_t callaction(int32_t id, void *data);
   virtual void net_recv(int32_t option, const void *data);

 private:
   void handle_user_login(const std::string &buf);

};

}; //namespace logic

#endif //APP_LOGICSERVER_LOGIC_LOGIN_CONTROLLER_H_
