/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id pack_enum.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/21 14:44
 * @uses The packet enum define.
*/
#ifndef PACK_ENUM_H_
#define PACK_ENUM_H_

namespace pack {

enum {

kLoginRequest = 0x0001,                             //请求登录
kLoginResponse = 0x0002,                            //登录响应
kLogicSupport = 0x0003,                             //逻辑系统消息

};

}; //namespace pack

#endif //PACK_ENUM_H_
