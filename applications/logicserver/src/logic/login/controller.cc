#include "game/login.pb.h"
#include "app/logicserver/logic/login/controller.h"

using LoginRequest = login::LoginRequest; //Same problem use same namespace.

namespace logic {

bool LoginController::setuplayout() { 
  std::cout << "logincontroller setuplayout" << std::endl; return true; 
}

int32_t LoginController::callaction(int32_t option, void *data) { 
  std::cout << "logincontroller::callaction: " 
            << option << "," 
            << data << std::endl; 
  return 0; 
}

void LoginController::net_recv(int32_t option, const void *data) { 
  auto buf = cast(const char *, data);
  switch (option) {
    case login::kUserLogin:
      handle_user_login(buf);
      break;
    default:
      break;
  }
};

void LoginController::handle_user_login(const std::string &buf) {
  LoginRequest msg; msg.ParseFromString(buf);
  pf_basic::io_cdebug(
      "logic-> user: %s | password: %s", 
      msg.user().c_str(), 
      msg.password().c_str());
}

} //namespace logic
