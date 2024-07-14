def is_prime(n):
    """Check if a number is prime."""
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def get_primes(n):
    """Get the first n prime numbers."""
    primes = []
    num = 2
    while len(primes) < n:
        if is_prime(num):
            primes.append(num)
        num += 1
    return primes

def print_octagon(size, primes):
    """Print an octagon pattern with prime numbers."""
    index = 0
    for i in range(size):
        print(" " * (size - i - 1) * 4, end="")
        for j in range(2 * i + 1):
            print(f"{primes[index]:4d}", end="")
            index += 1
        print()

    for i in range(size - 2, -1, -1):
        print(" " * (size - i - 1) * 4, end="")
        for j in range(2 * i + 1):
            print(f"{primes[index]:4d}", end="")
            index += 1
        print()

    for i in range(size - 2, -1, -1):
        print(" " * (size - i - 1) * 4, end="")
        for j in range(2 * i + 1):
            if index < len(primes):
                print(f"{primes[index]:4d}", end="")
                index += 1
        print()

# Calculate the first 1000 prime numbers
primes = get_primes(1000)

# Print an octagon with 5 numbers on each side
print_octagon(5, primes)