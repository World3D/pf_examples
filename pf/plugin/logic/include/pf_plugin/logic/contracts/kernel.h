/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id logic.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/15 14:28
 * @uses The logic plugin core class contract.
*/
#ifndef PF_PLUGIN_KERNEL_CONTRACTS_KERNEL_H_
#define PF_PLUGIN_KERNEL_CONTRACTS_KERNEL_H_

#include "pf_plugin/logic/contracts/config.h"

namespace pf_plugin {

namespace logic {

namespace contracts {

class Kernel {

 public:
   Kernel(id_t id) : 
     id_{id}, 
     module_{nullptr}, 
     view_{nullptr}, 
     controller_{nullptr} {}
   virtual ~Kernel() {}

 public:
   
   //Get logic system id.
   id_t getid() const { return id_; }
   
   //Get the module pointer.
   Module *module() { return module_.get(); }

   //Get the view pointer.
   View *view() { return view_.get(); }

   //Get the controller pointer.
   Controller *controller() { return controller_.get(); }

 public:
   friend class Module;
   friend class View;
   friend class Controller;

 private:
   
   //Set module pointer.
   void set_module(Module *module) { unique_move(Module, module, module_); }
   
   //Set view pointer.
   void set_view(View *view) { unique_move(View, view, view_); }
   
   //Set controller pointer.
   void set_controller(Controller *controller) { 
     unique_move(Controller, controller, controller_); 
   }

 private:
   id_t id_;
   std::unique_ptr<Module> module_;
   std::unique_ptr<View> view_;
   std::unique_ptr<Controller> controller_;

};

}; //namespace contracts

}; //namespace logic

}; //namespace pf_plugin

#endif //PF_PLUGIN_KERNEL_CONTRACTS_KERNEL_H_
