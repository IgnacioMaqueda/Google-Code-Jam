def number_to_char(number):
    return chr(number + ord('0'))


def char_to_number(char):
    return ord(char) - ord('0')


def append_number(X_string, X_int, index, number):
    X_string[index] = X_string[index] + number_to_char(number)
    X_int[index] *= 10
    X_int[index] += number
    return 1


def append_zeros(X_string, X_int, index):
    res = 0
    while X_int[index] <= X_int[index - 1]:
        res += append_number(X_string, X_int, index, 0)
    return res


def minimum_appends(N, X_string, X_int):
    res = 0
    for i in range(1, N):
        if X_int[i] <= X_int[i - 1]:
            if X_string[i - 1].startswith(X_string[i]) and X_string[i - 1] != X_string[i]:
                j = len(X_string[i - 1]) - 1
                while j >= len(X_string[i]) and X_string[i - 1][j] == '9':
                    j -= 1
                if j >= len(X_string[i]):
                    k = len(X_string[i])
                    while k < j:
                        res += append_number(X_string, X_int, i, char_to_number(X_string[i - 1][k]))
                        k += 1
                    res += append_number(X_string, X_int, i, char_to_number(X_string[i - 1][j]) + 1)
            res += append_zeros(X_string, X_int, i)
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        X_string = [x for x in input().split()]
        X_int = [int(x) for x in X_string]
        print(f"Case #{t + 1}: {minimum_appends(N, X_string, X_int)}")
