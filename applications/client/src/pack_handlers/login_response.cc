#include "game/login.pb.h"
#include "pack_enum.h"
#include "pack_handlers.h"
#include "pf_protobuf.h"

namespace pack {

/* uint32_t login_response(conn_t *connection, pack_t *packet) */
pack_handler(login_response) {
  auto temp = normalpack(packet);
  login::LoginResponse msg;
  protobuf_get(temp, msg);
  std::cout << "login_response: " << msg.err() << std::endl;
  return kPacketExecuteStatusContinue;
}

} //namespace pack
