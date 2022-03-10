# Examples
These are some example programs you can try out in asula lang!

## For Loops
For loops are a bit special. They require 3 parenthesis for the 3 clauses. The parenthesis can be of course empty.
```
for (var i(0), j(0)) (i < 10 & j < 10) (i += 1, j += 1)
    print(i + ", " + j)
end

# same as
for (var i(0)) (i < 5) (i += 1)
    for (var j(0)) (j < 6) (j += 1)
        print(i + ", " + j)
    end
end

for () () ()
    print("Infinite loop!")
end
```

## Ternary
Due to no inline if statements, you must use ternary instead:
```
def greater(a, b)
    ret(a > b ? a : b)
end

print(greater(1, 2)) # <= 2
```

## Comma Operator
Comma operators will evaluate left to right and return the final result.
```
var b(0)
var a(b += 1, 6)
print(a) # <= 6

# More practical use case
def make_x()
    var x(0)

    def increase_x()
        ret(x += 1, x)
    end
    
    return increase_x
end

var incr(make_x())
print(incr) # <= 1
print(incr) # <= 2
```
Note the comma operator is also used in for loops.

## Logic
There are no builtin operators for bitwise. Thus, we can get away with these programs:
```
var a(5), b(6)

if (a < b & a > 0)
    print("and operator!")
end

if (a > b | a > 0)
    print("or operator!")
end
```

You can easily invert an `if` statement:
```
var a(7), b(2)
if !(a < b)
    print("a is greater than b")
end

# same as
if (!(a < b))
    print("a is greater than b")
end

if (a != b)
    print("a is not equal to b")
end
```

`true` and `false` keywords work:
```
var bool(true)

if (bool == true)
    print("bool is true!")
elif (bool == false)
    print("bool is false!")
else
    print("bool is neither!")
end
```

## Math
You can do the normal math operations, and trigonometry!
```
var a(3), b(5)

print(a + b)
print(a - b)

print(a ^ b)

print(a * b)
print(a / b)

var ang(PI) # asula uses radians
print(sin(ang)) # 0
print(cos(ang)) # -1
print(tan(ang)) # 0

print(1 / 0 == inf) # <= true
```

### The NaN type
When a value is invalid, then the result is `nan`. This can be added to any other value, and it returns `nan`.

```
print("5" / 3) # <= nan
print("5" / 3 + 3) # <= nan
print(nan == nan) # <= true
```

Note `nan` is reflexive. `nan` so be **careful**.

# Edge cases
Due to asula lang's unique syntax, there are many edge cases to consider.

## Empty Variables
Empty variables use `()`:
```
var a # invalid
var a() # correct
var a(()) # correct

print(a) # <= ()

ret # invalid
ret() # correct
```

## Blocks in `if` statements
You don't have to use this syntax, but here's what it would look like:
```
if (true)
    block
        print("why?")
    end
end
```

## nullception
Since `()` is null, and you can surround it in parentheses, you could have an infinitely sized null:
```
print((((((((((((((())))))))))))))) # <= ()
```