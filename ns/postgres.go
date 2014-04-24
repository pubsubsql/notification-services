package ns

import (
	"fmt"
	"database/sql"
	_ "github.com/lib/pq"
)

/*
https://code.google.com/p/go-wiki/wiki/SQLDrivers
https://github.com/lib/pq
//
CREATE USER pubsubsql WITH PASSWORD 'pubsubsql';
GRANT ALL PRIVILEGES ON DATABASE "pubsubsql" to pubsubsql;
 */
func ConnectPostgres() {

	conn, err := sql.Open("postgres", "postgres://pubsubsql:pubsubsql@localhost/pubsubsql?sslmode=disable")
	if nil != err {
		fmt.Println(err)
		return
	}
	defer conn.Close()

	row := conn.QueryRow("select $1::int", 456)
	n := 0
	err = row.Scan(&n)
	if nil != err {
		fmt.Println(err)
		return
	}

	fmt.Println(n)
}
