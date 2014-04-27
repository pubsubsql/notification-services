1)
$MYSQL_HOME="C:\Program Files\MySQL\MySQL Server 5.6"
$MYSQL_SRC="Z:\mysql-5.6.17-win-src\mysql-5.6.17"

2)
cd %MYSQL_SRC%
mkdir bld
cd bld
cmake -G "Visual Studio 11 Win64" ..
devenv mysql.sln /build relwithdebinfo

3)
$MYSQL_HOME\lib\plugin

4)
cd %MYSQL_SRC%
mkdir build64
cd build64
cmake -G "Visual Studio 12 Win64" ..

5)
cd %MYSQL_SRC%
mkdir build32
cd build32
cmake -G "Visual Studio 12" ..


%%
