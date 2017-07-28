/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id module.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/15 15:38
 * @uses The logic plugin module contract class.
*/
#ifndef PF_PLUGIN_LOGIC_CONTRACTS_MODULE_H_
#define PF_PLUGIN_LOGIC_CONTRACTS_MODULE_H_

#include "pf_plugin/logic/contracts/kernel.h"

namespace pf_plugin {

namespace logic {

namespace contracts {

class Module {

 public:
   Module(Kernel *logic) : logic_{logic} { 
     logic_->set_module(this); 
   }
   virtual ~Module() {}

 public:
   void *get_data() { return data_; }
   void set_data(void *data) { data_ = data; }

 private:
   void *data_;
   Kernel *logic_;

};

}; //namespace contracts

}; //namespace logic

}; //namespace pf_plugin


#endif //PF_PLUGIN_LOGIC_CONTRACTS_MODULE_H_
