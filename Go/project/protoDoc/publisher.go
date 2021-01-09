package protoDoc

import (
	"log"
	math "math/rand"
	"golang.org/x/net/context"
	
)

type Publisher struct {

}

func(p * Publisher) Publish(ctx context.Context, msg * Message) (*Identity) {
	log.Printf("Received the fowling message to publish:\n")
	log.Printf("Tag: %s\n", msg.Tag)
	log.Printf("Text: %v", msg.Text)
	log.Printf("TimeStanp: %s", msg.Time) //dd:mm:yyyy::hh:mm

	return &Identity{Id: math.Int31n(100)}
}