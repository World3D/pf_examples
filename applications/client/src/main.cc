#include "game/login.pb.h"
#include "app/client/config.h"
#include "app/client/net.h"
#include "pack_enum.h"
#include "game/logic_enum.h"
#include "pf_protobuf.h"

void connector_loop(pf_engine::Kernel &engine,
                    pf_net::connection::manager::Connector &mconnector) {
  mconnector.tick();
  engine.enqueue([&engine, &mconnector](){ connector_loop(engine, mconnector); });
}

int main(int argc, char **argv) {

  /* Global vars. */
  GLOBALS["app.name"] = "client";

  /* Basic env. */
  if (!pf_engine::Application::env()) return 1;

  /* net init. */
  init_net_packets();
  
  /* Connection manager and create connection. */
  pf_net::connection::manager::Connector mconnector;
  mconnector.init(1);
  pf_net::connection::Basic *connector{nullptr};
  connector = mconnector.connect("127.0.0.1", 12360);
  if (is_null(connector)) {
    return 1;
  }

  /* Send normal packet with protobuf. */
  login::LoginRequest packet;
  packet.set_user("viticm");
  packet.set_password("123456");
  protobuf_send(*connector, pack::kLoginRequest, packet);

  /* Send logic packet with protobuf. */
  packet.set_password("654321"); //This will dirrent from normal packet.
  protobuf_lsend(*connector, 
                 pack::kLogicSupport, 
                 logic::kLogin, 
                 logic::login::kUserLogin, packet);

  /* Engine event. */
  pf_engine::Kernel engine;
  engine.enqueue([&engine, &mconnector](){ connector_loop(engine, mconnector); });
  
  /* App run. */
  pf_engine::Application app(&engine);
  app.run();

  return 0;
}
