# asula has no multiline comments!
# all functions are automatically loaded

# to import other files, use '$'
$("./copyright.asl")

# now i can use Copyright
Copyright().state()

def sum(a, b)
    ret(a + b)
end

var a(5)

print("5 + 5 is " + sum(a, 5))

def greet(person)
    if (person == "")
        ret()
    end

    print("Hello " + person + '!')
end

greet("You!")


# classes
class Person
    def new(name)
        self.name = "hi"
    end

    def say(text)
        print(self.name + " said hi")
    end
end

class Coder : Person
    def new(self, name)
        super(name)
    end

    def cry()
        print(self.name + " cried")
        self.say("Why programimng sucks???")
    end
end

you = Coder("you")
you.cry()

var i(0)
while i < 10
    print("i is " + i * 5)

    # +=, -=, *=, /=
    i += 1
end

# scope
block
    var a(5)
    block
        var a(10)
        print(a)
    end
    print(a)
end