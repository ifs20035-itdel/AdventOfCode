import hashlib

def searchAdventCoin(problem):
    number = 0

    while True:
        message = problem+str(number)
        result = hashlib.md5(message.encode()).hexdigest()
        print(result)
        if(result[0::4] == '00000'):
            break  
        number+=1
    problem = problem+str(number)
    return "Result : " + problem

if __name__ == "__main__":
    f = open("input.txt", "r") 
    input = f.read()

    searchAdventCoin(input)
