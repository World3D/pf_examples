#include "app/logicserver/net.h"
#include "app/logicserver/logic/support.h"

int main(int argc, char **argv) {

  /* Base config. */
  GLOBALS["app.debug"] = true;
  GLOBALS["app.name"] = "logicserver";

  //Net.
  GLOBALS["default.net.open"] = true;
  GLOBALS["default.net.service"] = true;
  GLOBALS["default.net.service_port"] = 12360;
  
  /* engine. */
  pf_engine::Kernel engine;
  pf_engine::Application app(&engine);

  /* net init. */
  init_net_packets();

  /* Logic enroll. */
  logic::enrolls();

  /* run */
  app.run(argc, argv);

  return 0;
}
