def print_right(line):
        n=len(line)
        print(" " * (30-n))
        print(line)
def triangle(word,n):
        for i in range(n):
                print(word * i)
def rectangle(word, r, c):
        for i in range(r):
                        print(word * c)
rectangle('l',5,4)
def bottle_verse(n):
        for i in range(n ,1,-1):
                print(i, " bottles of beer on the wall")
                print(i,"bottles of beer")
                print("take one down pass it around")
