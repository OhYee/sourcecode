import math 
import time 

def is_prime(number): 
    if number > 1: 
        if number == 2: 
            return True 
        if number % 2 == 0: 
            return False 
        for current in range(3, int(math.sqrt(number) + 1), 2): 
            if number % current == 0: 
                return False 
            return True 
    return False 


def get_primes(number): 
    while True: 
        if is_prime(number): 
            yield number 
            number += 1 

            start = time.time() 

            prime = get_primes(1) 
            prime_sum = 0 
            while True: 
                this_prime = next(prime) 
                if this_prime <= 1000000:#改一下这里的数字 
                    prime_sum += this_prime 
                else: 
                    break 
                print("Result:" + str(prime_sum)) 
                print ("Finished! Time Used: " + str(time.time() - start) + "s.") 