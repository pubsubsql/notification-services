# Install script for directory: C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MySQL")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql_com.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql_time.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_list.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_alloc.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/typelib.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin_audit.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin_ftparser.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin_validate_password.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_dbug.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/m_string.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_sys.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_xml.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql_embed.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_pthread.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/decimal.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/errmsg.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_global.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_net.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_getopt.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/sslopt-longopts.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_dir.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/sslopt-vars.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/sslopt-case.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/sql_common.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/keycache.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/m_ctype.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_attribute.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_compiler.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql_com_server.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/my_byteorder.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/byte_order_generic.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/byte_order_generic_x86.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/byte_order_generic_x86_64.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/little_endian.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/big_endian.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/build_windows_32/include/mysql_version.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/build_windows_32/include/my_config.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/build_windows_32/include/mysqld_ername.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/build_windows_32/include/mysqld_error.h"
    "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/build_windows_32/include/sql_state.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mysql" TYPE DIRECTORY FILES "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/include/mysql/" REGEX "/[^/]*\\.h$" REGEX "/psi\\_abi[^/]*$" EXCLUDE)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

