/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id system.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/17 10:37
 * @uses The logic plugin system class.
*/
#ifndef PF_PLUGIN_LOGIC_SYSTEM_H_
#define PF_PLUGIN_LOGIC_SYSTEM_H_

#include "pf_plugin/logic/contracts/kernel.h"

namespace pf_plugin {

namespace logic {

class PF_PLUGIN_API System {

 public:
   System() {};
   ~System() {};

 public:
   
   /* Enroll logic to system. */
   void enroll(contracts::Kernel *logic) {
     auto id = logic->getid();
     unenroll(id);
     std::unique_ptr<contracts::Kernel> p{logic};
     hash_[id] = std::move(p);
   }

   /* Unenroll logic from system. */
   void unenroll(id_t id) {
     auto it = hash_.find(id);
     if (it != hash_.end()) hash_.erase(it);
   }

   /* Unenroll logic from system. */
   void unenroll(contracts::Kernel *logic) {
     unenroll(logic->getid());
   }

   /* Get the logic. */
   contracts::Kernel *get(id_t id) { 
     return hash_[id].get();
   }
   
 private:
   std::map<id_t, std::unique_ptr<contracts::Kernel> > hash_;

};

}; //namespace logic

}; //namespace pf_plugin

#endif //PF_PLUGIN_LOGIC_SYSTEM_H_
