uninstall plugin pubsubsql;
install plugin pubsubsql soname 'ha_pubsubsql.dll';
drop table test;
create table test(d varchar(100)) engine = pubsubsql;
-- insert into test values (1);
select * from test;
