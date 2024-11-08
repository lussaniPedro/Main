import random

vetA = [random.randint(1, 10) for _ in range(10)]  
vetB = [random.randint(1, 10) for _ in range(10)]  

vetM = [a * b for a, b in zip(vetA, vetB)]

print(f"vetA: {vetA}")
print(f"vetB: {vetB}")
print(f"vetM: {vetM}")