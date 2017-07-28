#include "game/login.pb.h"
#include "pack_enum.h"
#include "pack_handlers.h"
#include "pf_protobuf.h"

namespace pack {

/* uint32_t handler_login_request(conn_t *connection, pack_t *packet) */
pack_handler(login_request) {
  login::LoginRequest msg; protobuf_get(packet, msg);
  pf_basic::io_cdebug(
      "normal-> user: %s | password: %s", 
      msg.user().c_str(), 
      msg.password().c_str());
  login::LoginResponse resmsg;
  resmsg.set_err(0);
  protobuf_send(*connection, kLoginResponse, resmsg);
  return kPacketExecuteStatusContinue;
}

} //namespace pack
