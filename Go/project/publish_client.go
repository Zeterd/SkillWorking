package main

import (
	"log"
	"net"
	"goole.org/x/net/context"
	"goole.golang.org/grpc"

	 pb"github.com/Zeterd/SkillWorking/Go/project"
)

func main()  {
	var conn *grpc.ClientConn

	conn, err := grpc.Dial(":9000", grpc.WithInsecure())

	if err != nil {
		log.Fatalf("Not able to connect on port :9000 %v", err)
	}
	
	defer conn.Close()

	c := pb.NewChatServiceClient(conn)

	msg := pb.Message{
		Tag: "lisence",
		Text: "GNU licence by Ubuntu 20.04LTS",
		TimeStanp: "09:01:2021::00:35:45"
	}

	response, err := c.SayHello(context.Background(), &msg)
	
	if err != nil {
		log.Fatalf("Error when calling SayHello: %s", err)
	}
	
	log.Printf("Response from server with ID: %s", response.Id)
}