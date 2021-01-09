package main

import (
	"flag"
	"log"
	"net"
	"strconv"
	"google.golang.org/grpc"
	"gituhub.com/Zeterd/SkillWorking/Go/project"
)
 

func main(){

	lis, err := net.Listen("tcp", ":9000")

	if err != nil {
		log.Fatalf("Error listen on port :9000 %v", err)
	}

	s := publisher.Server{}

	server := grpc.NewServer()

	publisher.RegisterChatServiceServer(server, &s)

	if err := server.Serve(lis); err != nil {
		log.Fatalf("Error to serve grpc server on port :9000: %v", err)
		return
	}

}
