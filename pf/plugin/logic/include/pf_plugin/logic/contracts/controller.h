/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id controller.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/15 11:35
 * @uses The logic plugin controller contract class.
*/
#ifndef PF_PLUGIN_LOGIC_CONTRACTS_CONTROLLER_H_
#define PF_PLUGIN_LOGIC_CONTRACTS_CONTROLLER_H_

#include "pf_plugin/logic/contracts/kernel.h"

namespace pf_plugin {

namespace logic {

namespace contracts {

class Controller {

 public:
   Controller(Kernel *logic) : logic_{logic} { logic_->set_controller(this); }
   virtual ~Controller() {}

 public:
   
   //Setup layout and show ui page.
   virtual bool setuplayout() = 0;

   //The action calls.
   virtual int32_t callaction(int32_t option, void *data) = 0;

   //Recv db data.
   virtual void db_recv(int32_t option, const void *data) {};

   //Recv net data.
   virtual void net_recv(int32_t option, const void *data) {};

   //Get the logic pointer.
   Kernel *logic() { return logic_; }

 private:
   Kernel *logic_;

};

}; //namespace contracts

}; //namespace logic

}; //namespace pf_plugin

#endif //PF_PLUGIN_LOGIC_CONTRACTS_CONTROLLER_H_
