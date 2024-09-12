package main

import (
	"container/list"
	"fmt"
	"sync"
	"time"
)

// go routine 1 that will push into queue - publisher
// publisher runs per 1 sec
func publisher(wg *sync.WaitGroup, mylist *list.List, mu *sync.Mutex) {
	defer wg.Done()

	for i := 0; i <= 10; i++ {
		mu.Lock()
		mylist.PushFront(i)
		mu.Unlock()
		time.Sleep(time.Second)
	}
}

// go routine 2 that will pull - suscriber
// suscriber eats per 2 sec
func suscriber(wg *sync.WaitGroup, mylist *list.List, mu *sync.Mutex) {
	defer wg.Done()

	for i := 0; i <= 10; i++ {
		mu.Lock()
		mylist.Remove(mylist.Back())
		mu.Unlock()
		time.Sleep(2 * time.Second)
	}

}

// another concurrent function that will wait till both are finished
// channels are references by default so no need to pass as pointers
func terminator(wg *sync.WaitGroup, terminatorChannel chan bool) {
	wg.Wait()
	<-terminatorChannel
}

func main() {

	// main queue structure - this will be a list
	mylist := list.New()

	// a channel that will have value boolean true by default
	terminatorChannel := make(chan bool, 1)
	terminatorChannel <- true

	//********  IMP ********** below is an example of unbuffered channel that causes deadlock
	// terminatorChannel:= make(chan bool)
	// flag:=true;
	// terminatorChannel<-flag;

	var wg sync.WaitGroup
	var mu sync.Mutex

	// run publisher and suscriber
	wg.Add(1)
	go publisher(&wg, mylist, &mu)
	go suscriber(&wg, mylist, &mu)
	go terminator(&wg, terminatorChannel)

	for len(terminatorChannel) > 0 {

		mu.Lock()
		fmt.Print("List contents: ")
		for x := mylist.Front(); x != nil; x = x.Next() {
			fmt.Print(x.Value, " ")
		}
		fmt.Println()
		mu.Unlock()

		time.Sleep(time.Second)
	}

	fmt.Println(".....all tasks are finished. Exiting")

}
