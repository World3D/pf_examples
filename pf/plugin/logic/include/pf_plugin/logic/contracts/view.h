/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id view.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/15 15:58
 * @uses The logic plugin view contract class.
 *       View always use in client ui or other art show.
*/
#ifndef PF_PLUGIN_LOGIC_CONTRACTS_VIEW_H_
#define PF_PLUGIN_LOGIC_CONTRACTS_VIEW_H_

#include "pf_plugin/logic/contracts/kernel.h"

namespace pf_plugin {

namespace logic {

namespace contracts {

class View {

 public:
   View(Kernel *logic) : logic_{logic} { logic_->set_view(this); }
   virtual ~View() {};

 public:
   virtual bool make(int32_t id = 0, void *data = nullptr) = 0;

 private:
   Kernel *logic_;

};

}; //namespace contracts

}; //namespace logic

}; //namespace pf_plugin


#endif //PF_PLUGIN_LOGIC_CONTRACTS_VIEW_H_
