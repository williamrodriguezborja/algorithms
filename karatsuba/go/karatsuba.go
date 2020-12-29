package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println("introduce first number")
	var n1 uint
	var n2 uint
	fmt.Scan(&n1)
	fmt.Println("introduce second number")
	fmt.Scan(&n2)
	fmt.Println(karatsuba(n1, n2))

}

func getDigits(num uint) uint {
	var result uint

	// corner case value is 0
	if num == 0 {
		return 1
	}

	// corner case value is negative
	if num < 0 {
		num = -num
	}

	// problem case

	for num > 0 {
		result++
		num = num / 10
	}
	return result
}

func getHighAndLowDigits(num uint, digits uint) (uint, uint) {
	divisor := uint(math.Pow(10, float64(digits)))

	if num >= divisor {
		return num / divisor, num % divisor
	} else {
		return 0, num
	}
}

func karatsuba(n1 uint, n2 uint) uint {
	if n1 == 0 && n2 == 0 {
		return 0
	}

	if n1 < 10 || n2 < 10 {
		return n1 * n2
	}

	n1Length := getDigits(n1)
	n2Length := getDigits(n2)

	var maxDigit uint

	if n1Length >= n2Length {
		maxDigit = n1Length
	} else {
		maxDigit = n2Length
	}

	middle :=maxDigit/2

	a, b := getHighAndLowDigits(n1, middle)
	c, d := getHighAndLowDigits(n2, middle)

	s1 := karatsuba(a, c)
	s2 := karatsuba(b, d)
	s3 := karatsuba(a  , d) + karatsuba(b  , c)
	p1:= s1 * uint(math.Pow(10 , float64(maxDigit)))
	p2:= s3 * uint(math.Pow(10, float64(maxDigit/2)))
	return  p1  + p2 + s2
}
