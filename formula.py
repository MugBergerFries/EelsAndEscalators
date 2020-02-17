

def coin_flip(n):

    if n == 1 or n == 2:
        return 2

    return float(((coin_flip(n-1) + coin_flip(n-2)) / 2) + 1)

print(coin_flip(10))