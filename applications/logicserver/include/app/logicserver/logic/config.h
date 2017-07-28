/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id config.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/19 19:01
 * @uses The login logic config file.
*/
#ifndef APP_LOGICSERVER_LOGIC_CONFIG_H_
#define APP_LOGICSERVER_LOGIC_CONFIG_H_

#include "app/logicserver/config.h"
#include "game/logic_enum.h"

#ifndef newself
#define newself(c,p) { auto t = new c (p); UNUSED(t); }
#endif

#ifndef logicclass
#define logicclass(n) \
class Logic##n : public pf_plugin::logic::contracts::Kernel { \
 \
 public: \
  Logic##n(pf_plugin::logic::id_t id) : \
     Kernel(id) { \
     newself(n##Module, this); \
     newself(n##View, this); \
     newself(n##Controller, this); \
   }; \
   virtual ~Logic##n() {}; \
 \
};
#endif

#ifndef newlogic
#define newlogic(s,n,id) {\
  logicclass(n) \
  s->enroll(new Logic##n(id)); \
}
#endif

#ifndef quote
#define quote(s) #s
#endif

#ifndef module_path
#define module_path(n) quote(app/logicserver/logic/n/module.h)
#endif

#ifndef view_path
#define view_path(n) quote(app/logicserver/logic/n/view.h)
#endif

#ifndef controller_path
#define controller_path(n) quote(app/logicserver/logic/n/controller.h)
#endif

#endif //APP_LOGICSERVER_LOGIC_CONFIG_H_
