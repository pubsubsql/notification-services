uninstall plugin pubsubsql;
install plugin pubsubsql soname 'ha_pubsubsql.dll';
drop table test;
create table test(c varchar(100)) engine = pubsubsql;
select * from test;
insert into test values('test');
insert into test values('test2');
insert into test values('test3');
select * from test;
delete from test;
select * from test;

