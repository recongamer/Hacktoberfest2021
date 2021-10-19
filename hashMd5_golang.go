package main

import (
	"crypto/md5"
	"fmt"
)

func main() {
	pass := "hardtoread*t142_*"

	hmd5 := md5.Sum([]byte(pass))
	fmt.Printf("md5 : %x\n", hmd5)
}
