package main

import (
	"fmt"
	"time"
)

var (
	currentTurn = 1
	totalTurns  = 5
)

func promodoroTurn(chanPromodoro chan bool) {
	tellBeginTurn()
	time.Sleep(time.Second * 25)
	tellEndTurn()
	chanPromodoro <- true
}

func promodoroBreak(chanBreak chan bool) {
	tellBeginSmallBreak()
	time.Sleep(time.Second * 5)
	tellEndSmallBreak()
	chanBreak <- true
}

func promodoroLongBreak(chanLongBreak chan bool) {
	tellBeginLongBreak()
	time.Sleep(time.Second * 30)
	tellEndLongBreak()
	chanLongBreak <- true
}

func tellBeginTurn() {
	fmt.Println("Promodoro round begins.")
}

func tellEndTurn() {
	fmt.Println("Round ended.")
}

func tellBeginSmallBreak() {
	fmt.Println("Have a small break!")
}

func tellEndSmallBreak() {
	fmt.Println("This is the end of the small break. Let's go back to work!")
}

func tellBeginLongBreak() {
	fmt.Println("Have a long break! You deserved it!")
}

func tellEndLongBreak() {
	fmt.Println("This is the end of the long break. Let's go back to work!")
}

func promodoroService(chanPromodoro, chanBreak, chanLongBreak, chanDone chan bool) {
	fmt.Println("Promodoro service started!\n")
	for {
		select {
		case endTurn := <-chanPromodoro:
			_ = endTurn
			if currentTurn >= totalTurns {
				go promodoroLongBreak(chanLongBreak)
				currentTurn = 1
			} else {
				currentTurn += 1
				go promodoroBreak(chanBreak)
			}

		case endSmallBreak := <-chanBreak:
			_ = endSmallBreak
			go promodoroTurn(chanPromodoro)

		case endLongBreak := <-chanLongBreak:
			_ = endLongBreak
			input := askAnotherSession()
			for input != "Y" && input != "N" {
				input = askAnotherSession()
			}

			if input == "Y" {
				go promodoroTurn(chanPromodoro)
			} else {
				chanDone <- true
			}
		}
	}
}

func askAnotherSession() string {
	fmt.Println("Ready for another pomodoro session? (Y/N)")
	var input string
	fmt.Scanln(&input)
	return input
}

func main() {
	turn := make(chan bool)
	smallBreak := make(chan bool)
	longBreak := make(chan bool)
	done := make(chan bool)

	go promodoroTurn(turn)
	go promodoroService(turn, smallBreak, longBreak, done)

	<-done
}
