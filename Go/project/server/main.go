package server

import (
	"log"
	"net"
	"google.golang.org/grpc"

	pb "github.com/Zeterd/SkillWorking/Go/project"
)
 

func main(){

	lis, err := net.Listen("tcp", ":9000")

	if err != nil {
		log.Fatalf("Error listen on port :9000 %v", err)
	}

	s := protoDoc.Server{}

	server := grpc.NewServer()

	protoDoc.RegisterChatServiceServer(server, &s)

	if err := server.Serve(lis); err != nil {
		log.Fatalf("Error to serve grpc server on port :9000: %v", err)
		return
	}

}
