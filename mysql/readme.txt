1)
MYSQL_HOME="C:\Program Files\MySQL\MySQL Server 5.6"
MYSQL_SRC="C:\home\workspace\go\src\github.com\notification-services\mysql\windows\mysql-5.6.17"

2)
cd %MYSQL_SRC%
mkdir build_windows_64
cd build_windows_64
cmake -G "Visual Studio 12 Win64" -DWITH_EXAMPLE_STORAGE_ENGINE=1 ..

3)
cd %MYSQL_SRC%
mkdir build_windows_32
cd build_windows_32
cmake -G "Visual Studio 12" -DWITH_EXAMPLE_STORAGE_ENGINE=1 ..

4)
cd %MYSQL_HOME%\lib\plugin

5)
create database pubsubsql;


%%
