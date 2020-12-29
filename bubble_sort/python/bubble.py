
def bubble_sort(arr:list):
    n = len(arr) 

    # Traverse through all array elements 
    for i in range(n): 
  
        # Last i elements are already in place 
        for j in range(0, n-i-1): 
  
            # traverse the array from 0 to n-i-1 
            # Swap if the element found is greater 
            # than the next element 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
  
    
    print('ordered: ',arr)
        


if __name__ == '__main__':
    # declare variables
    print("introduce numbers to sort")
    n = int(input())
    numbers = list()

    #read numbers
    for i in range(n):
        print(f"introduce n{i+1}: ")
        numbers.append(input())

    #print unordered numbers
    print('unordered: ',numbers)

    # order
    bubble_sort(numbers)
        #iterate numbers and
            #validate max value.
                #if 
                    #swap
                #else 
                    #ok
    # print ordered