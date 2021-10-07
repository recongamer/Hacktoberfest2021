package main

import (
  "fmt"
  "time"
)

func main() {
  weekday := time.Now().Weekday()
  if weekday == 3 {
    fmt.Println("It is Wednesday my dudes!")
  } else {
    fmt.Println("It is not Wednesday :-(")
  }
}
