package main

import (
	"time"
	"flag"
	"fmt"
	"log"

	"google.golang.org/grpc/grpclog"
)
)

var (
	port = strconv.Itoa(*flag.Int("port", 9000, "The server port"))
)


func main(){
	flag.Parse()

	lis, err := net.Listen("tcp", ":" + port)

	if err != nil {
		log.Fatalf("Error listen in port %s: %v", port, err)
		return
	}

	server := grpc.NewServer()

	if err := server.Serve(lis); err != nil {
		log.Fatalf("Error to serve grpc server on port %s: %v", port, err)
		return
	}

	




}
