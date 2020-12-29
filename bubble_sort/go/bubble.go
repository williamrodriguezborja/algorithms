package main

import "fmt"

func bubbleSort(list []uint) {
	for i := range list {
		for j := 0; j < len(list)-i-1; j++ {
			if list[j] > list[j+1] {
				swap := list[j]
				list[j] = list[j+1]
				list[j+1] = swap

			}
		}
	}
}

func main() {
	list := []uint{41, 22, 35, 11, 5, 99982, 3214, 52217, 1, 321, 43, 77, 32, 11, 25, 74, 78, 789, 123, 124, 357, 951, 741, 369, 32, 323, 321, 324, 3217, 3213697, 1152, 1, 12, 574, 37, 21}
	bubbleSort(list)
	fmt.Println(list)
}
