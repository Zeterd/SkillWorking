from math import sqrt
from math import floor

#Numbers
num = 10
print(num)

num = 34.7
print(num)
print(abs(num))
print(sqrt(num))
print(pow(num, 2))
print(round(num))
print(floor(num))

a = 10
b = 5

print(a+b)
print(a*b)
print(a-b)
print(float(a/b))

#Input

name = input("Whats yout name: ")
print("Hello " + name)

age = input("Whats ypur age: ")
print("You are " + age + "years old")
age = int(age) + 1
print("Nest year you are " + age + "years old")

#Strings

first_name = "Jose"
last_name = "Sousa"

full_name = name + last_name

print(full_name)

#Lists

friends = ["Guilherme", "Crisanto", "Solange", "Vitor", "Carlos", "Rita"]

print(friends.count())
print(friends)
print(friends.insert(1,"Luis"))
print(friends)
print(friends.sort())
print(friends)
print(friends.pop())
print(friends)
print(friends.reverse())
print(friends.index("Carlos"))
print(friends)
print(friends.append("Ana"))
#...

#Tuples

coordinates = (4,5)
print(coordinates)
print(coordinates[1]) #5

coordinates = [(1,3),(6,9),(3,-5),(2,4)]
print(coordinates)

#Functions

def say_hi(name):
    print("Hi " + name)

say_hi("Jose")

##Functions with return

def sum(n1,n2):
    return (n1+n2)

print(sum(4,4))
num = sum(4.1,6.7)

#IF statement

num = 2
flag = True

if num%2 == 0 and flag:
    print("É par!!")

elif not(flag) or 1==1:
    print("Tuna is fish, i dont fucking know!!")

else:
    print("É impar!!")

##Must complex ifs

def max3(n1,n2,n3):
    if n1>=n2 and n1>=n3:
        return n1
    elif n2>=n1 and n2>=n3:
        return n2
    elif n3>=n1 and n3>=n2:
        return n3
    else:
        return -1

print(max3(3,6,2))

#Dictionaries

months = {
    "Jan":"January",
    "Feb":"Febuary",
    "Mar":"March",
    "Apr":"April",
    "May":"May",
    "Jun":"June",
    "Jul":"Jully",
    "Aug":"August",
    "Sep":"September",
    "Oct":"October",
    "Nov":"November",
    "Dez":"Dezember"

}

print(months.get("Feb"))

#Loops

##While

i=0
while i<=10:
    print(i)
    i += 1

##For

friends = ["Guilherme", "Solange", "Crisanto"]

for i in friends:
    print(i)

for h in range(10):
    print(h)

#2D lists and Nested loops

grid = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

print(grid)

for row in grid:
    print(row)
    for index in row:
        print(index)

#Try and except

try:
    name = int(input("Enter your full name: "))
    print("You name is: " + name)
except ValueError:
    print("Your input is not valid!!")







