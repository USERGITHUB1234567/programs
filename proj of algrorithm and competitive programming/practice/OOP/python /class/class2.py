from abc import *
class animal:
    def __init__(self, name, age):
        self.name=name
        self.age=age
    @ abstractmethod
    def speak(self):
        pass
class dog(animal):
    def __init__(self,name,age,col):
        super().__init__(name,age)
        self.col=col
    def speak(self):
        return f"gau gau"
d=dog("alpha",1,"red")
print(f"{d.name} {d.age} {d.col}")
#sd lớp trừu tượng nhân viên sau đó có lớp con nv văn pgongf sau đó là lớp con nv thực tập. Tính lương nv văn phòng và thực tập
