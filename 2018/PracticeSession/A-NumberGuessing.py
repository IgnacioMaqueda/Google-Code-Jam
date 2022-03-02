if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        A, B = [int(x) + 1 for x in input().split()]
        N = int(input())
        answer = ""
        while answer != "CORRECT":
            guess = (A + B) // 2
            print(guess)
            answer = input()
            if answer == "TOO_SMALL":
                A = guess
            elif answer == "TOO_BIG":
                B = guess
