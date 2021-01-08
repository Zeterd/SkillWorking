package main

import (
	"log"
	"math/rand"
	"golang.org/x/net/context"
	"protoDoc"
)

type Publisher struct {

}

func(p * Publisher) Publish(ctx context.Context, msg * Message) (*Identity, err) {
	log.Printf("Received the fowling message to publish:\n")
	log.Printf("Tag: %s\n", msg.Tag)
	log.Printf("Text: %v", msg.Text)
	log.Printf("TimeStanp: %s", msg.Time)

	return &Identity{Id: Intn(100)}, nil
}