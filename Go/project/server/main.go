package main

import (
	"flag"
	"log"
	"net"
	"strconv"
	"github.com/Zeterd/SkillWorking/Go/project/protoDoc"
	"google.golang.org/grpc"
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

	s := publisher.Server{}

	server := grpc.NewServer()

	publisher.RegisterChatServiceServer(server, &s)

	if err := server.Serve(lis); err != nil {
		log.Fatalf("Error to serve grpc server on port %s: %v", port, err)
		return
	}

}
