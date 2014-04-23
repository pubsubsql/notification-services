package main

import (
	"fmt"
	"github.com/pubsubsql/notification-services/ns"
)

func main() {
	ns.ConnectMysql();
	fmt.Println("Done.")
}
