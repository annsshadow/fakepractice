L = [1,2,3,4,5,6,7,8,9]
print(L[::1])
print(L[:8:1])
print(L[-2::1])
print(L[-2::-1])
print(L[-2:0:-1])
print(L[-2:0:-2])

def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1
    return 'done'

def odd():
    print('step 1')
    yield 1
    print('step 2')
    yield(3)
    print('step 3')
    yield(5)

 g = fib(6)
while True:
	try:
		x = next(g)
		print('g:', x)
	except StopIteration as e:
		print('Generator return value:', e.value)
		break