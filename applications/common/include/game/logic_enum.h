/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id logic_enum.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/22 09:27
 * @uses The game logic enum define.
*/
#ifndef GAME_LOGIC_ENUM_H_
#define GAME_LOGIC_ENUM_H_

namespace logic {

//The group enum.
enum {
  kLogin = 0x0001,                                //登录系统
};

//The group self sub system.
namespace login {
  enum {
    kUserLogin = 0x0001,                          //玩家登录子系统
  };
};

};

#endif //GAME_LOGIC_ENUM_H_
