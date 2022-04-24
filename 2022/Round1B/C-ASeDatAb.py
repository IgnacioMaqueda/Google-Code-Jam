import random

if __name__ == '__main__':
    with_one = []
    with_two = []
    with_three = []
    with_four = []
    for i in range(256):
        i_string = format(i, '08b')
        if i_string.count('1') == 1:
            with_one.append(i_string)
        elif i_string.count('1') == 2:
            with_two.append(i_string)
        elif i_string.count('1') == 3:
            with_three.append(i_string)
        elif i_string.count('1') == 4:
            with_four.append(i_string)
    j = 4
    T = int(input())
    for t in range(T):
        print("00000000")
        answer = int(input())
        while answer > 0:
            if answer > 4:
                print("11111111")
            elif answer == 4:
                print(random.choice(with_four))
            elif answer == 3:
                print(random.choice(with_three))
            elif answer == 2:
                print(random.choice(with_two))
            elif answer == 1:
                print(random.choice(with_one))
            answer = int(input())
