

def coin_flip(n):

    if n == 1 or n == 2:
        return 2

    return float(((coin_flip(n-1) + coin_flip(n-2)) / 2) + 1)

def coin_flip_fuck_recursion(n):
    
    step = 2
    answers = [2.0, 2.0]
    while(step != n):
        answers.append(((answers[step-1] + answers[step-2]) / 2) + 1)
        step += 1 

    return answers[n-1]

def die(n):
    
    step = 6
    answers = [6.0] * 6
    while(step != n):
        answers.append((sum(answers[step-6:step+1]) / 6) + 1)
        step += 1 

    return answers[n-1]

# print(coin_flip(30))
print(die(100))