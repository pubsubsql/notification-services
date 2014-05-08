#!/usr/bin/perl
# Call mtr in out-of-source build
$ENV{MTR_BINDIR} = "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/build_windows_64";
chdir("C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/mysql-test");
exit(system($^X, "C:/home/workspace/go/src/github.com/notification-services/mysql/windows/mysql-5.6.17/mysql-test/mysql-test-run.pl", @ARGV) >> 8);
