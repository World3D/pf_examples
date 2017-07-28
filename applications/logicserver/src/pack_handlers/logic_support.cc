#include "pack_enum.h"
#include "pack_handlers.h"
#include "pf_protobuf.h"
#include "app/logicserver/logic/support.h"

namespace pack {

/* uint32_t handler_logic_support(conn_t *connection, pack_t *packet) */
pack_handler(logic_support) {
  auto pack = logicpack(packet);
  if (is_null(g_logic_system)) return kPacketExecuteStatusContinue;
  auto logic = g_logic_system->get(pack->get_logic_id());
  if (!is_null(logic)) 
    logic->controller()->net_recv(pack->get_option(), pack->get_str());
  return kPacketExecuteStatusContinue;
}

} //namespace pack
