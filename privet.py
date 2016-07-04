import math
class mult:
    def __init__(self):
        self.x = 10
    def multiply(self, y):
        print("Hohoho")
        c = self.x * y
        print("The result is: ", c)
        # self.x = y
        return c
    def info(self):
        print("I am working from c++")
    def rd_init(self, x):
        self.x = x
    def calculate_super_sin(self, ang, huyang):
        c = math.cos(ang) * math.sin(huyang)
        print("Privet, ya tut naschial: ", c)
    def print_arr(self, x):
        print("Length: ", len(x))
        for i in range(len(x)):
            print("Element:", x[i])


