import hashlib

def searchAdventCoin(problem):
    number = 0
    hash_message = ""
    while hash_message[0:5] != "000000":
        message = problem + str(number)
        hash_message = hashlib.md5(message.encode()).hexdigest()
        print(f'Try {message} >> {hash_message}')
        number+=1
    problem = problem+str(number)
    return "Result : " + problem

if __name__ == "__main__":
    f = open("input.txt", "r") 
    input = f.read()
    lines = input.split('\n')

    searchAdventCoin(lines[0])
