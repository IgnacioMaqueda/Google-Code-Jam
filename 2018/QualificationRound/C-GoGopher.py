def caso20():
    for k in range(1000):
        print('{} {}'.format(2, (k % 5) + 2))
        respuesta20 = input()
        if respuesta20 == '0 0':
            return 0
        elif respuesta20 == '-1 -1':
            return -1
    return -1


def caso200():
    for l in range(1000):
        print('{} {}'.format(2, (k % 65) + 2))
        respuesta200 = input()
        if respuesta200 == '0 0':
            return 0
        elif respuesta200 == '-1 -1':
            return -1
    return -1


T = int(input())

for t in range(T):
    A = int(input())
    if A == 20:
        res20 = caso20()
        if res20 == -1:
            break
    else:
        res200 = caso200()
        if res200 == -1:
            break
