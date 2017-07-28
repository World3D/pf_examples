#include "pf_plugin/protocol/basic.h"
#include "pack_enum.h"
#include "pack_handlers.h"

#define R(a,b) pf_plugin::protocol::register_packet_handler(a,handler_##b)
#define RL(a,b) pf_plugin::protocol::register_logic_packet_handler(a,handler_##b)

void init_net_packets() {
  using namespace pack;

  //Protocol init.
  pf_plugin::protocol::init();

  //Register handlers.
  R(kLoginRequest, login_request);
  RL(kLogicSupport, logic_support);
}
