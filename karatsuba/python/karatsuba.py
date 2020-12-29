# karatsuba function
def karatsuba(n1, n2):
    if not n1 and not n2:
        return 0
    # first case.
    if n1 < 10  or n2 < 10:
        return n1 * n2

    n1 = int(n1)
    n2 = int(n2)

    n1_lenght= get_length_number(n1)
    n2_lenght= get_length_number(n2)

    
    max_length = max(n1_lenght, n2_lenght)
    middle = max_length/2


    a, b = split_number(n1, middle)
    c, d = split_number(n2, middle)

    s1 = karatsuba(a, c)
    s2 = karatsuba(b , d)
    s3 = karatsuba(a, d) + karatsuba(b , c)

    return s1 * pow(10, max_length) + s3 * pow(10, max_length /2) + s2
    
 
def split_number(number, high):
    divisor = pow(10, high)
    if number >= divisor:
        return int(number / divisor), int(number % divisor)
    else:
        return 0 , number

def give_me_num(name):
    print(f'insert {name}')
    num = input()
    return int(num)


def get_length_number(num:int):
    if num ==0 or  num < 10:
        return 1
    length = 0
    while int(num) > 0:
        num = num / 10
        length = length + 1
    return length


if __name__ =='__main__':
    n1 = give_me_num('n1')
    n2 = give_me_num('n2')
    print(karatsuba(n1, n2))