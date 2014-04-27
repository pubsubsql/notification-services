#!/usr/bin/perl
# Call mtr in out-of-source build
$ENV{MTR_BINDIR} = "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/build64";
chdir("C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/mysql-test");
exit(system($^X, "C:/Users/Mykhailo/workspace/go/github.com/pubsubsql/notification-services/mysql/windows/mysql-5.6.17/mysql-test/mysql-test-run.pl", @ARGV) >> 8);
