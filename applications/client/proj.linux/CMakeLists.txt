# This file generate by plain framework admin tool, date: 2017-05-21 12:55:51
SET(EXECUTABLE_OUTPUT_PATH ../../bin)

ADD_DEFINITIONS(-DPF_BUILD_AS_DLL)
ADD_DEFINITIONS(-DPF_OPEN_EPOLL)
SET(USE_32BITS 0)

IF(CMAKE_SYSTEM MATCHES Linux)
  ADD_DEFINITIONS(-D_REENTRANT)
  ADD_DEFINITIONS(-DDONT_TD_VOID)
  ADD_DEFINITIONS(-DLUA_USE_LINUX)
ELSE(CMAKE_SYSTEM MATCHES Linux)
ENDIF(CMAKE_SYSTEM MATCHES Linux)

LINK_DIRECTORIES(
  "./"
  "./../../../pf/core/dll/"
  "./../../../pf/dll/"
  "./../../../pf/dependencies/dll/"
)

INCLUDE_DIRECTORIES(
  "../../../pf/core/include/"
  "../include/"
  "../../../pf/plugin/protocol/include/"
  "../../common/include/"
  "../../common/proto/src/"
)


SET (INCLUDE_LIST
)


SET (SRC_LIST
  ../src/main.cc
  ../src/net.cc
  ../src/pack_handlers/login_response.cc
  ../../common/proto/src/game/login.pb.cc
)

ADD_EXECUTABLE(client
  ${SRC_LIST}
)

if (WIN32)
TARGET_LINK_LIBRARIES(client ws2_32.lib pf_core.lib pf_plugin_protocol.lib protobuf.lib)
else()
TARGET_LINK_LIBRARIES(client pf_core pf_plugin_protocol protobuf)
  if(USE_32BITS)
    SET(CMAKE_C_FLAGS "-Wall -ggdb -pipe -march=i386 -mtune=i686")
    SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -ggdb -pipe -march=i386 -mtune=i686")
  else()
    SET(CMAKE_C_FLAGS "-Wall -ggdb -pipe -march=x86-64 -mtune=i686")
    SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -ggdb -pipe -march=x86-64 -mtune=i686")
  endif(USE_32BITS)
endif(WIN32)
