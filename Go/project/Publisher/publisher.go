package project

import (
	"log"
	math "math/rand"
	"golang.org/x/net/context"
	pb "github.com/Zeterd/SkillWorking/Go/project/protoDoc"
)

type Publisher struct {

}

func(p * Publisher) Publish(ctx context.Context, msg * pb.Message) (*pb.Identity) {
	log.Printf("Received the fowling message to publish:\n")
	log.Printf("Tag: %s\n", msg.Tag)
	log.Printf("Text: %v", msg.Text)
	log.Printf("TimeStanp: %s", msg.Time)

	return &pb.Identity{Id: math.Int31n(100)}
}