# Asula Lang
Asula Lang is a language exploring new syntax methods.

For example, variables do not use `=` signs:
```
var i(5)
```

There are no semicolons.

# Example programs
These are simple programs to show you around Asula! The file extension for a typical Asula file is `.asu`. For example `main.asu` is the main file you run. [See more programs...](./idea/examples.md)

## Hello, World
```
print("Hello World!")
```

## Null Type
`()` is actually the null type! 
```
print(()) # => ()
var a(()) # same as var a()
if (a == ())
    print("a is null! Proof: " + a) # <= ()
else
    print("a has a value! a:" + a)
end
```

## Blocks
```
block
    var a(5)
    block
        var a(3)
        print(a)
    end
    print(a)
end
```

## Functions
```
def sum(a, b, c)
    ret(a + b + c)
end

print(sum(1, 2, 3))
```

## Modules
Asula can directly execute a file you give it, unlike europa lang.
```
$("./hello.asu")
print("World!")

# ./hello.asu
print("Hello, ")
```

## Classes
Unlike europa lang, there are classes in asula!
```
class Animal
    def new(species)
        self.species = species
    end

    def identify()
        print(self.species)
    end
end

class Dog : Animal
    def new(species)
        super(species)
    end
end
```

`super` and `self` are automatically defined 'variables' you can use.

## Control Flow
You can either use ternary or if statements, however, unlike europa, if statements are not expressions.
```
var a(5), b(6)

if (a > b)
    print("a > b")
elif (a < b)
    print('a < b')
else
    print("a = b")
end
```

# Europa Lang
Asula is in a way related to europa lang. Originally, someone else was meant to create asula lang (J4Mirror), however, they never did, so I will!

Now, if I get an `Option::unwrap()` on a `None` value, I can go here for a segfault!