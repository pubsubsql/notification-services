# Install script for directory: C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Readme")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE OPTIONAL FILES
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/COPYING"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/LICENSE.mysql"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Readme")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Readme")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/README")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Readme")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/docs" TYPE FILE FILES
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/Docs/INFO_SRC"
    "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/Docs/INFO_BIN"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/docs" TYPE DIRECTORY FILES "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/Docs/" REGEX "/install\\-binary$" EXCLUDE REGEX "/makefile\\.[^/]*$" EXCLUDE REGEX "/glibc[^/]*$" EXCLUDE REGEX "/linuxthreads\\.txt$" EXCLUDE REGEX "/myisam\\.txt$" EXCLUDE REGEX "/mysql\\.info$" EXCLUDE REGEX "/sp\\-imp\\-spec\\.txt$" EXCLUDE)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/zlib/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/extra/yassl/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/extra/yassl/taocrypt/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/libevent/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/archive/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/blackhole/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/csv/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/example/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/federated/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/heap/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/innobase/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/myisam/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/myisammrg/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/ndb/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/storage/perfschema/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/plugin/audit_null/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/plugin/auth/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/plugin/daemon_example/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/plugin/fulltext/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/plugin/innodb_memcached/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/plugin/password_validation/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/plugin/semisync/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/include/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/dbug/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/strings/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/vio/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/regex/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/mysys/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/mysys_ssl/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/libmysql/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/unittest/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/unittest/examples/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/unittest/mytap/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/unittest/mytap/t/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/unittest/gunit/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/extra/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/tests/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/client/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/sql/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/sql/share/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/libservices/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/libmysqld/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/libmysqld/examples/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/mysql-test/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/mysql-test/lib/My/SafeProcess/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/support-files/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/scripts/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/sql-bench/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/packaging/rpm-uln/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/packaging/rpm-oel/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/packaging/rpm-fedora/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/packaging/WiX/cmake_install.cmake")
  INCLUDE("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/packaging/solaris/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build32/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
