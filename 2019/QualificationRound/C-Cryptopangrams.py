import math


def decodificar(ls):
    j = 0
    while ls[j] == ls[j + 1]:
        j = j + 1
    primo = math.gcd(ls[j], ls[j + 1])
    if j % 2 == 0:
        primo = ls[j] // primo
    lista_primos = [primo]
    solucion_l = [primo]
    for k in range(len(ls)):
        primo = ls[k] // primo
        solucion_l.append(primo)
        if lista_primos.count(primo) == 0:
            lista_primos.append(primo)
    lista_primos.sort()
    solucion_s = ''
    for k in range(len(solucion_l)):
        solucion_s += chr(ord('A') + lista_primos.index(solucion_l[k]))
    return solucion_s


T = int(input())
for i in range(1, T + 1):
    N, L = input().split()
    Ls = [int(j) for j in input().split()]
    sol = decodificar(Ls)
    print('Case #{}: {}'.format(i, sol))
