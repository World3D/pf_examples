/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id support.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/20 10:28
 * @uses your description
*/
#ifndef APP_LOGICSERVER_LOGIC_SUPPORT_H_
#define APP_LOGICSERVER_LOGIC_SUPPORT_H_

#include "app/logicserver/logic/config.h"

namespace logic {

void enrolls();

};

extern std::unique_ptr<pf_plugin::logic::System> g_logic_system;

#endif //APP_LOGICSERVER_LOGIC_SUPPORT_H_
