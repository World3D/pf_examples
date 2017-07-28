/**
 * PLAIN FRAMEWORK ( https://github.com/viticm/plainframework )
 * $Id pack_handlers.h
 * @link https://github.com/viticm/plainframework for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.ti@gmail.com>
 * @date 2017/07/21 14:54
 * @uses The packet handlers define.
*/
#ifndef PACK_HANDLERS_H_
#define PACK_HANDLERS_H_

/* Define a packet handler function. */
#ifndef pack_handler
#define pack_handler(n) uint32_t handler_##n(conn_t *connection, pack_t *packet)
#endif

#include "pf.h"

namespace pack {

using conn_t = pf_net::connection::Basic;
using pack_t = pf_net::packet::Interface;

/* login { */
pack_handler(login_request);
pack_handler(login_response);
/* } login */

/* logic */
pack_handler(logic_support);

}; //namespace pack

#endif //PACK_HANDLERS_H_
