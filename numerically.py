from simulate import *

times_to_run = 10000
turns = []

for i in range(times_to_run):
    turns.append(simulate_game(Ladders, Snakes))

average_run = float(sum(turns) / times_to_run)

print(average_run)