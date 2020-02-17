import random

Ladders = {
    1: 38,
    4: 14,
    9: 31,
    21: 42,
    28: 84,
    36: 44, 
    51: 67,
    71: 91,
    80: 100,
}

Snakes = {
    16: 6,
    47: 26,
    49: 11,
    56: 53,
    62: 19,
    64: 60,
    87: 24,
    93: 73,
    95: 75,
    98: 78,
}

def simulate_game(Ladders, Snakes):
    turns = 0
    spot = 0

    while spot != 100:
        roll = random.randint(1,6)
        spot += roll
        if spot > 100:
            spot -= roll
        else:
            # see if we're on a special spot, otherwise stay at the current spot
            spot = Ladders.get(spot, spot)
            spot = Snakes.get(spot, spot)

        turns += 1

    return turns

# print(f"number of turns = {simulate_game(Ladders, Snakes)}")