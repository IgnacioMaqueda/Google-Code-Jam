import bisect


def generate_all_roarings(limit):
    res = []
    i = 1
    while i * i < limit:
        year = str(i) + str(i + 1)
        j = i + 2
        while int(year) < limit:
            res.append(int(year))
            year = year + str(j)
            j += 1
        i += 1
    res.sort()
    res.append(1234567)
    return res


def next_roaring_year(Y, roarings):
    i = bisect.bisect(roarings, Y)
    return roarings[i]


if __name__ == '__main__':
    T = int(input())
    roarings = generate_all_roarings(1000000)
    for t in range(T):
        Y = int(input())
        print(f"Case #{t + 1}: {next_roaring_year(Y, roarings)}")
