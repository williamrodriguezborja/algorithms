package main

import "fmt"

func splitArray(data []int) ([]int, []int) {

	low := make([]int, 0)
	high := make([]int, 0)
	middle := len(data) / 2
	for i, num := range data {

		if i+1 <= middle {
			low = append(low, num)
		} else {
			high = append(high, num)
		}
	}

	return low, high
}

func swap(n1 *int, n2 *int) {
	temp := *n1
	*n1 = *n2
	*n2 = temp
}

func mergeSort(data []int) []int {
	// corner case
	if len(data) == 0 {
		return data
	}

	// first case
	if len(data) == 2 {
		swap(&data[0], &data[1])
		return data
	}

	low, high := splitArray(data)
	low = mergeSort(low)
	high = mergeSort(high)
	return low
}

func main() {
	data := []int{33, 22, 1, -4, 35, 12347, 2, 7413, 37}

	low, high := splitArray(data)
	fmt.Println(low, high)
}
