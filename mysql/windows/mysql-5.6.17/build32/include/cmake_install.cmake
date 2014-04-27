# Install script for directory: C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files/MySQL")
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
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql_com.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql_time.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_list.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_alloc.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/typelib.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin_audit.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin_ftparser.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql/plugin_validate_password.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_dbug.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/m_string.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_sys.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_xml.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql_embed.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_pthread.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/decimal.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/errmsg.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_global.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_net.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_getopt.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/sslopt-longopts.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_dir.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/sslopt-vars.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/sslopt-case.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/sql_common.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/keycache.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/m_ctype.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_attribute.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_compiler.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql_com_server.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/my_byteorder.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/byte_order_generic.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/byte_order_generic_x86.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/byte_order_generic_x86_64.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/little_endian.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/big_endian.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/include/mysql_version.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/include/my_config.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/include/mysqld_ername.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/include/mysqld_error.h"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/include/sql_state.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mysql" TYPE DIRECTORY FILES "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/include/mysql/" REGEX "/[^/]*\\.h$" REGEX "/psi\\_abi[^/]*$" EXCLUDE)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

