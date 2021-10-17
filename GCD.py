def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)

if __name__ == '__main__':
    a,b = map(int, input('Enter Input : ').split())
    if a == b == 0:
        print('Error! must be not all zero.')
        exit()
    gcd = GCD(a, b)
    if gcd < 0 and a < 0 and b < 0:
        print(f'The gcd of {min(a, b)} and {max(a, b)} is : {- gcd}')
    else:
        print(f'The gcd of {max(a, b)} and {min(a, b)} is : {abs(gcd)}')