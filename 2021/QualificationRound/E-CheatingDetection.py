if __name__ == '__main__':
    T = int(input())
    P = int(input())
    for t in range(T):
        max = 0
        for i in range(1, 101):
            answers = input()
            corrects = answers.count('1')
            if corrects > max:
                pos_max = i
                max = corrects
        print(f"Case #{t + 1}: {pos_max}")
