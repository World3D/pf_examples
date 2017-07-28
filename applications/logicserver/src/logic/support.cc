#include "app/logicserver/logic/support.h"
#include "game/logic_enum.h"

/* MVC */
#include module_path(login)
#include view_path(login)
#include controller_path(login)

std::unique_ptr<pf_plugin::logic::System> g_logic_system{nullptr};

namespace logic {

void enrolls() {
  if (is_null(g_logic_system)) {
    auto logic_system = new pf_plugin::logic::System;
    unique_move(pf_plugin::logic::System, logic_system, g_logic_system);
  }
  if (is_null(g_logic_system)) return;
  newlogic(g_logic_system, Login, kLogin);
}

}; //namespace logic
