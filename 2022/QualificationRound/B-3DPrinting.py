def printed_color(inks):
    res = []
    remaining = 1000000
    for i in range(4):
        ammount = min(remaining, min([inks[j][i] for j in range(3)]))
        res.append(ammount)
        remaining -= ammount
    if remaining > 0:
        return ["IMPOSSIBLE"]
    else:
        return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        inks = []
        for i in range(3):
            inks.append([int(x) for x in input().split()])
        print(f"Case #{t + 1}: ", end='')
        print(*printed_color(inks))
